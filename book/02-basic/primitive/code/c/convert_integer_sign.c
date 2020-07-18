/*
 * project: ntsdb
 * file: convert_integer_sign.c
 * chapter: basic
 * section: primitive
 * description: show behavior of converting signed and unsigned integer in c
 * compile: gcc convert_interger.c
 * run: ./a.out
 */

#include <stdio.h>

int main() {
    // 1000_000 interpreted as signed is -128, i.e. -2^7 + 0
	char c = -128;
	// 1000_000 interpreted as unsigned is 128, i.e. 2^7
	unsigned char uc = (unsigned char) c;
	printf("%d %u\n", c, uc); // -128, 128
	return 0;
}
