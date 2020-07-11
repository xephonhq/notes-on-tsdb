/*
* project: ntsdb
* file: endianness_file.c
* chapter: basic
* section: primitive
* description: show endianess when reading/writing string/int to file
* compile: gcc endianess_file.c
* run: ./a.out
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// write integer using the in memory layout directly, i.e. little-endian
void write_file(const char* file_name, int a) {
    FILE *f = fopen(file_name, "w");
    size_t wrote = fwrite(&a, 1, sizeof(a), f);
    assert(wrote == 4);
    fclose(f);
}

// read raw bytes as integer, only works if it is using same layout as memory
int read_int(const char* file_name) {
    FILE *f = fopen(file_name, "r");
    int val = -1;
    size_t read = fread(&val, 1, sizeof(val), f);
    assert(read == 4);
    fclose(f);
    return val;
}

int main() {
    const char* file_name = "f1.bin";
    int val = 256 + 2;
    // 256 + 2 is 0b1_00000010
    write_file(file_name, val);
    printf("wrote %d got %d\n", val, read_int(file_name));
    return 0;
}
