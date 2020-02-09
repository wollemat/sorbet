#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

        if (ptr < tape || ptr > tape + NUMBER_OF_CELLS - 1) break;
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
    int bracket_counter = 0;
    for (int i = 0; i < len; i++) {
        char c = (char) fgetc(fp);
        if (c == '[') bracket_counter++;
        if (c == ']') bracket_counter--;
        src[i] =  c;
    }
    src[len] = '\0';
    fclose(fp);
    if (bracket_counter > 0) {
        printf("Unmatched '[': program is invalid\n");
        exit(EXIT_FAILURE);
    }
    if (bracket_counter < 0) {
        printf("Unmatched ']': program is invalid\n");
        exit(EXIT_FAILURE);
    }
    return src;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Invalid arguments. Usage: sorbet file.\n");
        exit(EXIT_FAILURE);
    }

    clock_t start = clock();

    char* src = read_file(argv[1]);
    interpret(src);
    free(src);

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", cpu_time_used);

    exit(EXIT_SUCCESS);
}
