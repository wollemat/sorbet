#include <stdlib.h>
#include <stdio.h>

const int NUMBER_OF_CELLS = 30000;

void interpret(char* src) {
    char tape[NUMBER_OF_CELLS] = {0};
    char* ptr = tape;

    while (1) {
        int c = *src;

        if (c == '\0') return;
        else if (c == '>') ++ptr;
        else if (c == '<') --ptr;
        else if (c == '+') ++*ptr;
        else if (c == '-') --*ptr;
        else if (c == '.') putchar(*ptr);
        else if (c == ',') *ptr = (char) getchar();
        else if (c == '[') {
            if (*ptr == 0) {
                int brackets = 1;
                while (brackets != 0) {
                    ++src;
                    c = *src;
                    if (c == '[') ++brackets;
                    if (c == ']') --brackets;
                }
            }
        }
        else if (c == ']') {
            if (*ptr != 0) {
                int brackets = 1;
                while (brackets != 0) {
                    --src;
                    c = *src;
                    if (c == '[') --brackets;
                    if (c == ']') ++brackets;
                }
            }
        }

        ++src;
    }
}


char* read_file(char* name) {
    FILE *fp = fopen(name, "r");
    if (fp == NULL) {
        printf("%s could not be opened or otherwise failed to open.\n", name);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* src = malloc(len + 1);
    for (int i = 0; i < len; i++) src[i] = (char) fgetc(fp);
    src[len] = '\0';
    fclose(fp);
    return src;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Invalid arguments. Usage: sorbet file.\n");
        exit(EXIT_FAILURE);
    }

    char* src = read_file(argv[1]);
    interpret(src);
    free(src);

    exit(EXIT_SUCCESS);
}
