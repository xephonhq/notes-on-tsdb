/*
 * project: ntsdb
 * file: truncate_integer.c
 * chapter: basic
 * section: primitive
 * description: show behavior of truncating signed integer in c
 * compile: gcc convert_interger.c
 * run: ./a.out
 */

#include <stdio.h>

int main() {
    short sa1 = 0x0100;
    char ca1 = (char) sa1;
    printf("%d %d\n", sa1, ca1); // 256 0
    short sa2 = 0x00ff;
    char ca2 = (char) sa2;
    printf("%d %d\n", sa2, ca2); // 255 -1
    return 0;
}
