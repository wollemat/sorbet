#include <stdlib.h>
#include <stdio.h>

char tape[30000] = {0};
char* ptr = tape;

int main() {

ptr += 4;
*ptr += 1;
ptr += 1;
*ptr += 3;
ptr += 1;
*ptr += 3;
ptr += 5;
*ptr += 3;
while (*ptr) {
ptr += 1;
*ptr = getchar();
*ptr += 1;
ptr += 1;
*ptr += 4;
while (*ptr) {
ptr += 1;
*ptr += 4;
ptr -= 1;
*ptr -= 1;
}
ptr += 1;
while (*ptr) {
ptr -= 2;
while (*ptr) {
*ptr -= 1;
while (*ptr) {
*ptr -= 1;
ptr += 1;
}
}
ptr += 1;
while (*ptr) {
ptr -= 1;
}
ptr += 1;
*ptr -= 1;
}
ptr -= 2;
while (*ptr) {
ptr += 1;
*ptr += 1;
ptr += 1;
*ptr += 1;
ptr += 2;
*ptr += 1;
ptr += 1;
*ptr += 1;
while (*ptr) {
ptr -= 4;
}
ptr -= 1;
*ptr += 1;
ptr += 2;
while (*ptr) {
*ptr += 1;
ptr -= 1;
}
ptr -= 1;
while (*ptr) {
ptr += 1;
}
ptr += 1;
*ptr += 1;
while (*ptr) {
while (*ptr) {
ptr += 3;
}
ptr += 2;
*ptr += 1;
while (*ptr) {
ptr -= 4;
}
ptr += 1;
*ptr -= 1;
}
*ptr += 1;
ptr -= 1;
*ptr += 1;
ptr += 3;
*ptr -= 1;
while (*ptr) {
ptr -= 2;
*ptr += 1;
while (*ptr) {
ptr += 1;
}
ptr += 2;
*ptr += 1;
ptr -= 3;
*ptr += 1;
ptr -= 1;
*ptr += 1;
ptr -= 1;
*ptr -= 8;
while (*ptr) {
ptr -= 2;
*ptr -= 1;
ptr -= 2;
*ptr += 1;
while (*ptr) {
ptr += 1;
}
ptr += 1;
*ptr += 1;
ptr -= 2;
*ptr -= 1;
ptr -= 2;
*ptr -= 1;
while (*ptr) {
ptr -= 3;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr += 2;
}
ptr -= 1;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
ptr -= 3;
*ptr -= 1;
ptr -= 1;
*ptr -= 4;
while (*ptr) {
ptr -= 3;
*ptr -= 1;
ptr += 4;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr -= 3;
*ptr += 1;
while (*ptr) {
ptr += 1;
}
ptr += 1;
*ptr += 1;
ptr -= 2;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr -= 2;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
ptr -= 1;
*ptr += 1;
while (*ptr) {
ptr += 2;
}
ptr -= 1;
*ptr += 1;
ptr -= 4;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr -= 2;
*ptr -= 1;
while (*ptr) {
ptr += 1;
}
ptr += 2;
*ptr -= 1;
ptr -= 3;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr -= 3;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr += 2;
}
ptr -= 1;
*ptr += 1;
ptr -= 3;
*ptr += 1;
ptr -= 1;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr -= 4;
*ptr += 1;
while (*ptr) {
ptr += 1;
}
ptr -= 1;
*ptr -= 1;
ptr -= 2;
*ptr -= 1;
while (*ptr) {
ptr -= 2;
*ptr += 1;
while (*ptr) {
ptr += 1;
}
ptr += 2;
*ptr -= 1;
ptr -= 4;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr += 5;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
ptr -= 3;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr += 2;
*ptr += 1;
ptr -= 2;
*ptr -= 1;
while (*ptr) {
ptr -= 2;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr += 1;
}
ptr += 1;
*ptr += 1;
ptr -= 2;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr -= 2;
*ptr += 1;
ptr -= 1;
*ptr += 1;
while (*ptr) {
ptr += 1;
}
ptr -= 1;
*ptr += 1;
ptr -= 1;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr += 2;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
while (*ptr) {
ptr -= 2;
*ptr -= 1;
while (*ptr) {
ptr += 1;
}
ptr -= 1;
*ptr += 1;
ptr -= 1;
*ptr += 4;
while (*ptr) {
ptr -= 1;
*ptr -= 8;
ptr += 1;
*ptr -= 1;
}
*ptr += 2;
ptr -= 1;
while (*ptr) {
ptr -= 2;
*ptr += 1;
while (*ptr) {
ptr += 1;
}
ptr += 2;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
ptr -= 4;
*ptr -= 1;
while (*ptr) {
ptr -= 2;
*ptr -= 1;
ptr -= 2;
*ptr -= 1;
ptr += 4;
*ptr -= 1;
while (*ptr) {
ptr -= 4;
*ptr += 1;
while (*ptr) {
ptr += 1;
}
ptr += 1;
*ptr += 1;
ptr -= 4;
*ptr -= 1;
while (*ptr) {
ptr -= 2;
*ptr += 1;
ptr -= 2;
*ptr -= 1;
while (*ptr) {
ptr += 2;
}
ptr -= 1;
*ptr += 1;
ptr -= 5;
*ptr -= 1;
while (*ptr) {
ptr += 4;
*ptr -= 1;
ptr -= 3;
*ptr -= 1;
ptr -= 1;
*ptr -= 1;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
ptr += 1;
while (*ptr) {
ptr += 1;
while (*ptr) {
while (*ptr) {
while (*ptr) {
ptr -= 4;
}
ptr += 1;
*ptr += 1;
ptr += 2;
while (*ptr) {
ptr += 5;
}
ptr -= 1;
*ptr -= 1;
}
ptr -= 1;
}
ptr += 3;
*ptr += 1;
ptr += 7;
*ptr += 1;
ptr += 1;
}
ptr -= 1;
}
ptr -= 1;
*ptr = 0;
ptr -= 7;
*ptr += 2;
ptr -= 1;
*ptr += 3;
ptr -= 1;
*ptr += 3;
while (*ptr) {
while (*ptr) {
ptr += 1;
}
ptr += 6;
*ptr += 8;
while (*ptr) {
ptr -= 2;
*ptr += 4;
ptr += 1;
*ptr += 6;
ptr += 1;
*ptr -= 1;
}
ptr -= 1;
*ptr -= 1;
ptr -= 2;
while (*ptr) {
*ptr -= 1;
while (*ptr) {
ptr -= 1;
*ptr += 1;
ptr += 2;
putchar(*ptr);
ptr -= 1;
*ptr -= 1;
}
}
ptr -= 4;
while (*ptr) {
*ptr -= 1;
while (*ptr) {
*ptr -= 1;
while (*ptr) {
ptr += 1;
*ptr += 1;
ptr -= 1;
*ptr -= 1;
}
ptr += 1;
}
ptr += 5;
while (*ptr) {
putchar(*ptr);
while (*ptr) {
ptr += 1;
}
}
ptr -= 2;
while (*ptr) {
ptr -= 1;
*ptr += 1;
ptr += 1;
*ptr -= 1;
}
ptr += 3;
while (*ptr) {
ptr -= 2;
*ptr += 2;
while (*ptr) {
ptr -= 1;
*ptr += 1;
ptr += 1;
*ptr -= 2;
}
ptr += 2;
*ptr -= 1;
}
ptr -= 2;
while (*ptr) {
*ptr -= 1;
ptr += 1;
*ptr += 1;
ptr -= 1;
while (*ptr) {
ptr -= 1;
*ptr += 2;
ptr += 1;
*ptr -= 1;
}
}
ptr -= 3;
while (*ptr) {
ptr -= 1;
*ptr += 1;
ptr += 1;
*ptr -= 1;
}
ptr -= 4;
}
ptr += 2;
*ptr += 1;
ptr += 3;
*ptr -= 2;
while (*ptr) {
ptr -= 1;
*ptr += 1;
ptr += 1;
*ptr -= 3;
}
ptr -= 1;
putchar(*ptr);
ptr += 2;
while (*ptr) {
*ptr = 0;
ptr -= 2;
}
ptr -= 1;
}

exit(EXIT_SUCCESS);
}
