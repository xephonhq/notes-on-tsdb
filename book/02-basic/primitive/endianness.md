# Endianness

## TODO

- [ ] go example?
- [ ] mention `hexdump` `xxd`

## Overview

- `byte` i.e. 8 bits is the atomic unit, endianness is for byte ordering. (for the scope in this book)
- `big-endian`, save MSB (Most Significant Byte) in the smallest address
- `little-endian`, save LSB (Least Significant Byte) in the smallest address
- most processors are `little-endian`
- network order is `big-endian`
- numeric literal, left is MSB, i.e. `big-endian` if memory address starts from left
- bit shift, shift left shift towards MSB, e.g. `0x0400 << 1` is `0x0800`

Example [code/c/endianness.c](code/c/endianness.c)

`2^10+1` when written in literal is `100_0000_0001` or `0x0401` (hex), it requires two bytes

```text
memory address: 0          8
big-endian    : 0000_0100  0000_0001
little-endian : 0000_0001  0000_0100
```

## File

- [ ] text format have BOM

File can use either ordering as long as you can read what you write.
Normally file content is in a well known serialized format, e.g. text format like plain text, json or binary format like ELF.
Serialized content is a byte array and the layout on disk is same as the memory.
Endianess is handled by the encoder and decoder when converting types to and from bytes.

We can write integer to file directly as bytes, this is a straight forward (and unsafe) serialization.
For languages like C, we can cast int to char array directly ([example endianness_file.c](code/c/endianness_file.c)), the endianness is same as in processor layout.
For languages that is more type safe, (~~we can use unsafe~~) we can shift the bits to generate a byte array from integer.

```bash
xxd f1.bin
00000000: 0201 0000
```

## Tool

You can use `hexdump` or `xxd` to inspect binary files.

```bash
xxd <file>
# output in hex format
address: word1 word2

xxd -b <file>
# output in binary format
```

## Reference

- https://en.wikipedia.org/wiki/Endianness