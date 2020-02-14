#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

const char* START_FILE =
        "#include <stdlib.h>\n"
        "#include <stdio.h>\n"
        "#include <time.h>\n"
        "\n"
        "char tape[30000] = {0};\n"
        "char* ptr = tape;\n"
        "\n"
        "int main() {\n"
        "clock_t start = clock();\n"
        "\n";

const char* END_FILE =
        "\n"
        "printf(\"\\n\\nExecution time: %f seconds\\n\", ((double) (clock() - start)) / CLOCKS_PER_SEC);\n"
        "exit(EXIT_SUCCESS);\n"
        "}\n";

const char* OUT_OP = "putchar(*ptr);\n";
const char* IN_OP = "*ptr = getchar();\n";
const char* OPEN_OP = "while (*ptr) {\n";
const char* CLOSE_OP = "}\n";

void transpile(char* src) {
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
        }
        else if (c == '-') {
            int acc = 1;
            while (fgetc(rfp) == '-') acc++;
            fseek(rfp, -1, SEEK_CUR);
            sprintf(buffer, "*ptr -= %d;\n", acc);
            fwrite(buffer, 1, strlen(buffer), wfp);
        }
        else if (c == '>') {
            int acc = 1;
            while (fgetc(rfp) == '>') acc++;
            fseek(rfp, -1, SEEK_CUR);
            sprintf(buffer, "ptr += %d;\n", acc);
            fwrite(buffer, 1, strlen(buffer), wfp);
        }
        else if (c == '<') {
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

void run() {
    system("gcc ./bin/generated.c -O3 -o ./bin/generated");
    system("./bin/generated");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Invalid arguments. Usage: sorbet file.\n");
        exit(EXIT_FAILURE);
    }

    transpile(argv[1]);
    run();

    exit(EXIT_SUCCESS);
}
