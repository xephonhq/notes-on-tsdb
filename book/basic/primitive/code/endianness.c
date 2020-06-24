/*
* project: ntsdb
* file: endianness.c
* chapter: basic
* section: primitive
* description: show endianess of integer
* compile: gcc endianess.c
* run: ./a.out
*/

#include <stdio.h>

// NOTE: based on CSAPP Figure 2.4

void show_bytes(unsigned char* start, size_t len) {
    for (int i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((unsigned char*) &x, sizeof(x));
}

int main() {
    // 01 04 00 00
    // 1025 is 2^10+1, which is 0x0401, print starts from smaller memory address, 01 is LSB and prints before 04
    show_int(1025);

    // 1024 2048
    printf("%d %d\n", 0x0400, 0x0400 << 1);
}