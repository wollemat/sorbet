#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

const char *START_FILE =
        "#include <stdlib.h>\n"
        "#include <stdio.h>\n"
        "\n"
        "char tape[30000] = {0};\n"
        "char* ptr = tape;\n"
        "\n"
        "int main() {\n"
        "\n";

const char *END_FILE =
        "\n"
        "exit(EXIT_SUCCESS);\n"
        "}\n";

const char *OUT_OP = "putchar(*ptr);\n";
const char *IN_OP = "*ptr = getchar();\n";
const char *OPEN_OP = "while (*ptr) {\n";
const char *CLOSE_OP = "}\n";

void transpile(char *src) {
    mkdir("./bin", S_IRWXU);
    FILE *rfp = fopen(src, "r");
    FILE *wfp = fopen("./bin/generated.c", "w");

    fwrite(START_FILE, 1, strlen(START_FILE), wfp);

    char buffer[1024] = {0};
    char c;
    while ((c = (char) fgetc(rfp)) != EOF) {

        /**
         * Optimize the Brainf*ck sequence "[-]" from a loop that runs
         * in the worst case 255 time to a constant time operation.
         */
        if (c == '[') {
            char c2 = (char) fgetc(rfp);
            char c3 = (char) fgetc(rfp);
            if (c2 == '-' && c3 == ']') {
                sprintf(buffer, "*ptr = 0;\n");
                fwrite(buffer, 1, strlen(buffer), wfp);
                continue;
            } else {
                fseek(rfp, -2, SEEK_CUR);
            }
        }

        /**
         * Contract the operations. For example "++++" evaluates to "*ptr += 4".
         */
        if (c == '+') {
            int acc = 1;
            while (fgetc(rfp) == '+') acc++;
            fseek(rfp, -1, SEEK_CUR);
            sprintf(buffer, "*ptr += %d;\n", acc);
            fwrite(buffer, 1, strlen(buffer), wfp);
        } else if (c == '-') {
            int acc = 1;
            while (fgetc(rfp) == '-') acc++;
            fseek(rfp, -1, SEEK_CUR);
            sprintf(buffer, "*ptr -= %d;\n", acc);
            fwrite(buffer, 1, strlen(buffer), wfp);
        } else if (c == '>') {
            int acc = 1;
            while (fgetc(rfp) == '>') acc++;
            fseek(rfp, -1, SEEK_CUR);
            sprintf(buffer, "ptr += %d;\n", acc);
            fwrite(buffer, 1, strlen(buffer), wfp);
        } else if (c == '<') {
            int acc = 1;
            while (fgetc(rfp) == '<') acc++;
            fseek(rfp, -1, SEEK_CUR);
            sprintf(buffer, "ptr -= %d;\n", acc);
            fwrite(buffer, 1, strlen(buffer), wfp);
        }

            /**
             * Arbitrarily implement the other 4 Brainf*ck operations.
             */
        else if (c == '.') fwrite(OUT_OP, 1, strlen(OUT_OP), wfp);
        else if (c == ',') fwrite(IN_OP, 1, strlen(IN_OP), wfp);
        else if (c == '[') fwrite(OPEN_OP, 1, strlen(OPEN_OP), wfp);
        else if (c == ']') fwrite(CLOSE_OP, 1, strlen(CLOSE_OP), wfp);
    }

    fwrite(END_FILE, 1, strlen(END_FILE), wfp);

    fclose(rfp);
    fclose(wfp);
}

void compile(char *arg) {
    char command[80];
    strcpy(command, "gcc ./bin/generated.c ");
    if (strcmp(arg, "--optimized") == 0) {
        strcat(command, "-O3 ");
    } else {
        strcat(command, "-O0 ");
    }
    strcat(command, "-o ./bin/generated");

    printf("%s\n\n", command);
    system(command);
}

void run() {
    system("./bin/generated");
    system("clear");
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        printf("Usage: sorbet file [--optimized|--default].\n\n");
        printf("--optimized: \tWhen compiling the generated C code the optimization flag -O3 is used.\n");
        printf("--default: \tWhen compiling the generated C code the optimization flag -O0 is used.\n");
        exit(EXIT_FAILURE);
    }

    if (argc < 3) {
        printf("Invalid arguments. Usage: sorbet file [--optimized|--default].\n");
        exit(EXIT_FAILURE);
    }

    clock_t start = clock();
    transpile(argv[1]);

    clock_t  check_1 = clock();
    compile(argv[2]);

    clock_t check_2 = clock();
    run();

    clock_t end = clock();
    printf("Transpilation time: %f seconds\n", ((double) (check_1 - start)) / CLOCKS_PER_SEC);
    printf("Compilation time: %f seconds\n", ((double) (check_2 - check_1)) / CLOCKS_PER_SEC);
    printf("Execution time: %f seconds\n", ((double) (end - check_2)) / CLOCKS_PER_SEC);
    printf("Total time: %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    exit(EXIT_SUCCESS);
}
