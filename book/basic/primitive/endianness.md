# Endianness

- `byte` i.e. 8 bits is the atomic unit, endianness is for byte ordering. (for the scope in this book)
- big-endian, save MSB (Most Significant Byte) in the smallest address
- little-endian, save LSB (Least Significant Byte) in the smallest address
- most processors are little endian
- network order is big endian
- numeric literal, left is MSB
- bit shift, shift left shift towards MSB, e.g. `0x0400 << 1` is `0x0800`

Example [code](code/endianness.c)

`2^10+1` when written in literal is `100_0000_0001` or `0x0401` (hex), it requires two bytes

```text
memory address: 0          8
big-endian    : 0000_0100  0000_0001
little-endian : 0000_0001  0000_0100
```

## Reference

- https://en.wikipedia.org/wiki/Endianness