#include <stdlib.h>
#include <stdio.h>

void interpret(char* input) {
    char tape[30000] = {0};
    char* ptr = tape;
    char current_char;
    size_t i;
    size_t loop;

    for (i = 0; input[i] != 0; i++) {
        current_char = input[i];
        if (current_char == '>') {
            ++ptr;
        } else if (current_char == '<') {
            --ptr;
        } else if (current_char == '+') {
            ++*ptr;
        } else if (current_char == '-') {
            --*ptr;
        } else if (current_char == '.' ) {
            putchar(*ptr);
        } else if (current_char == ',') {
            *ptr = getchar();
        } else if (current_char == '[') {
            continue;
        } else if (current_char == ']' && *ptr) {
            loop = 1;
            while (loop > 0) {
                current_char = input[--i];
                if (current_char == '[') {
                    loop--;
                } else if (current_char == ']') {
                    loop++;
                }
            }
        }
    }
}

char* read_source(char* name) {
    FILE *file;
    char *source;
    file = fopen(name, "r");
    if (file == NULL) {
        printf("File %s could not be opened\n", name);
        exit(EXIT_FAILURE);
    }
    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    source = malloc(file_size);
    rewind(file);
    fread(source, 1, file_size, file);
    fclose(file);
    return source;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Invalid arguments. Usage: sorbet file\n");
        exit(EXIT_FAILURE);
    }

    char *input = read_source(argv[1]);
    interpret(input);

    free(input);
    exit(EXIT_SUCCESS);
}
