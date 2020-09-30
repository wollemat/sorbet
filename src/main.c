#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

const char *file_start = // Boilerplate start of C source.
        "#include <stdlib.h>\n" // Import C standard library.
        "#include <stdio.h>\n" // Import C input output library.
        "\n"
        "char tape[30000] = {0};\n" // Initialise character tape.
        "char* ptr = tape;\n" // Initialise pointer.
        "\n"
        "int main() {\n" // Declare main function.
        "\n";

const char *file_end = // Boilerplate end of C source.
        "\n"
        "exit(EXIT_SUCCESS);\n" // Exit the program successfully.
        "}\n";

const char *op_output = "putchar(*ptr);\n";
const char *op_input = "*ptr = getchar();\n";
const char *op_loop_start = "while (*ptr) {\n";
const char *op_loop_end = "}\n";

/**
 * Write the contracted and optimised version of repeated Brainf*ck operations.
 *
 * @param src_file File pointer to Brainf*ck source.
 * @param gen_file File pointer to generated C source
 * @param bf_op The Brainf*ck operation to be contracted.
 * @param c_op The C operation to transpile to.
 * @param buffer The character buffer to write the optimised operation to.
 */
void contract(FILE *src_file, FILE *gen_file, const char bf_op, const char *c_op, char *buffer) {
    int acc = 1;
    while (fgetc(src_file) == bf_op) acc++;
    fseek(src_file, -1, SEEK_CUR);
    sprintf(buffer, "%s %d;\n", c_op, acc);
    fwrite(buffer, 1, strlen(buffer), gen_file);
}

/**
 * Transpile Brainf*ck source code to C source code.
 * The transpiled code is written to './tmp/generated.c'
 *
 * @param src The character string representing the Brainf*ck source.
 */
void transpile(char *src) {
    mkdir("./tmp", S_IRWXU); // Create directory used for generated source
    FILE *src_file = fopen(src, "r"); // Open Brainf*ck source file.
    FILE *gen_file = fopen("./tmp/generated.c", "w"); // Open C source file.

    fwrite(file_start, 1, strlen(file_start), gen_file); // Write required start boilerplate to file.

    char buffer[1024] = {0}; // Character buffer used for writing to generated file.
    char c; // Current Brainf*ck operation.

    while ((c = (char) fgetc(src_file)) != EOF) { // Loop source until the 'EOF' character is reached.

        /**
         * Optimize the Brainf*ck sequence "[-]" from a loop that runs
         * in the worst case 255 time to a constant time operation.
         */
        if (c == '[') {
            char c2 = (char) fgetc(src_file); // Check for '-' operation.
            char c3 = (char) fgetc(src_file); // Check for ']' operation.
            if (c2 == '-' && c3 == ']') { // If operations match then:
                sprintf(buffer, "*ptr = 0;\n"); // Buffer optimised C code.
                fwrite(buffer, 1, strlen(buffer), gen_file); // Write buffer to generated file.
                continue; // Transpile to next Brainf*ck operation.
            } else { // If operations do not match then:
                fseek(src_file, -2, SEEK_CUR); // Reset consumed operations.
            }
        }

        /**
         * Contract the '+', '-', '<' and '>' operations.
         * For example "++++" evaluates to "*ptr += 4".
         */
        if (c == '+') contract(src_file, gen_file, '+', "*ptr +=", buffer); // Contract '+' operation.
        else if (c == '-') contract(src_file, gen_file, '-', "*ptr -=", buffer); // Contract '-' operation.
        else if (c == '>') contract(src_file, gen_file, '>', "ptr +=", buffer); // Contract '>' operation.
        else if (c == '<') contract(src_file, gen_file, '<', "ptr -=", buffer); // Contract '<' operation.

        else if (c == '.') fwrite(op_output, 1, strlen(op_output), gen_file); // Transpile '.' operation.
        else if (c == ',') fwrite(op_input, 1, strlen(op_input), gen_file); // Transpile ',' operation.
        else if (c == '[') fwrite(op_loop_start, 1, strlen(op_loop_start), gen_file); // Transpile '[' operation.
        else if (c == ']') fwrite(op_loop_end, 1, strlen(op_loop_end), gen_file); // Transpile ']' operation.
    }

    fwrite(file_end, 1, strlen(file_end), gen_file); // Write required end boilerplate to file.

    fclose(src_file); // Close Brainf*ck source file.
    fclose(gen_file); // Close C source file.
}

/**
 * The main function. This is where the program starts.
 *
 * @return Returns EXIT_SUCCESS when the program succeeds else returns EXIT_FAILURE.
 */
int main(int argc, char **argv) {
    if (argc < 2) { // Check if enough arguments are used when Sorbet is called.
        printf("Invalid arguments. Usage: sorbet file.\n"); // Print usage message.
        exit(EXIT_FAILURE); // Exit program unsuccessfully.
    }

    transpile(argv[1]); // Transpile Brainf*ck source code to C source code.
    system("gcc ./tmp/generated.c -O3 -o ./tmp/generated"); // Compile generated C source code.
    system("./tmp/generated"); // Execute compiled program.

    exit(EXIT_SUCCESS); // Exit program successfully.
}
