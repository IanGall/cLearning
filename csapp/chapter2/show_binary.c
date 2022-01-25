#include <stdio.h>

// Assumes little endian
void printBits(size_t const size, void const *const ptr) {
    unsigned char *b = (unsigned char *) ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
            if (j % 4 == 0) {
                printf(" ");
            }
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    int i = 0x0027C8F8;
    float f = 23.45f;
    printBits(sizeof(i), &i);
    printBits(sizeof(f), &f);
    return 0;
}