# Endianness

## TODO

- [ ] what happens when you write a string as file (in c, go), what the layout on disk?
  - mention BOM? though it not really that related to TSDB
- [ ] mention `hexdump` `xxd`

## Overview

- `byte` i.e. 8 bits is the atomic unit, endianness is for byte ordering. (for the scope in this book)
- `big-endian`, save MSB (Most Significant Byte) in the smallest address
- `little-endian`, save LSB (Least Significant Byte) in the smallest address
- most processors are `little-endian`
- network order is `big-endian`
- numeric literal, left is MSB, i.e. `big-endian` if memory address starts from left
- bit shift, shift left shift towards MSB, e.g. `0x0400 << 1` is `0x0800`

Example [code/endianness.c](code/endianness.c)

`2^10+1` when written in literal is `100_0000_0001` or `0x0401` (hex), it requires two bytes

```text
memory address: 0          8
big-endian    : 0000_0100  0000_0001
little-endian : 0000_0001  0000_0100
```

## File

- [ ] a go example, though cgo might cause problem ...

When write content to file, you need to determine the endianness explicitly. i.e. convert other types to a byte array.
For languages like C, use address of the integer of its size allow it to be treated as a char array, and the endianness is same as in processor layout.

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