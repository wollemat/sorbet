#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

const char* START_FILE =
        "#include <stdlib.h>\n"
        "#include <stdio.h>\n"
        "\n"
        "char tape[30000] = {0};\n"
        "char* ptr = tape;\n"
        "\n"
        "int main() {\n"
        "\n";

const char* END_FILE =
        "\n"
        "   exit(EXIT_SUCCESS);\n"
        "}\n";

const char* INC_VAL_OP = "++*ptr;\n";
const char* DEC_VAL_OP = "--*ptr;\n";
const char* INC_PTR_OP = "ptr++;\n";
const char* DEC_PTR_OP = "ptr--;\n";
const char* OUT_OP = "putchar(*ptr);\n";
const char* IN_OP = "*ptr = getchar();\n";
const char* OPEN_OP = "while (*ptr) {\n";
const char* CLOSE_OP = "}\n";

void transpile(char* src) {
    mkdir("./bin", S_IRWXU);
    FILE *rfp = fopen(src, "r");
    FILE *wfp = fopen("./bin/generated.c", "w");

    fwrite(START_FILE, 1, strlen(START_FILE), wfp);

    char c;
    while ((c = (char) fgetc(rfp)) != EOF) {
        if (c == '+') fwrite(INC_VAL_OP, 1, strlen(INC_VAL_OP), wfp);
        else if (c == '-') fwrite(DEC_VAL_OP, 1, strlen(DEC_VAL_OP), wfp);
        else if (c == '>') fwrite(INC_PTR_OP, 1, strlen(INC_PTR_OP), wfp);
        else if (c == '<') fwrite(DEC_PTR_OP, 1, strlen(DEC_PTR_OP), wfp);
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

    clock_t start = clock();

    transpile(argv[1]);
    run();

    printf("\n\nExecution time: %f seconds\n", ((double) (clock() - start)) / CLOCKS_PER_SEC);

    exit(EXIT_SUCCESS);
}
