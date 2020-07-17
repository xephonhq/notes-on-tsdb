# Integer

## TODO

- [ ] shift
  - [ ] what type can use the shift operator? byte, int, can double use it?
- [ ] emphasis [bijection](https://en.wikipedia.org/wiki/Bijection,_injection_and_surjection) for encoding
- [ ] why use two's complement encoding instead of one bit for sign
  - bijection

## Unsigned Integer

- [ ] the B2U graph from csapp?
- [ ] mathjax support

Unsigned integer use `w` bits to represent unsigned integer value range from `0` to `2^w - 1`.
e.g. `unsigned int` in C is 32 bits and range from `0` to `4294967295`.

```text
val = sum(bits[i] * 2^i)
```

Example 4 bit unsigned integer

- `0001` is `0 + 0 + 0 + 1` = `1`
- `1001` is `8 + 0 + 0 + 1` = `9`

## Signed Integer

A straw man approach is use one bit from unsigned integer as the sign, 0 for positive, 1 for negative. 
This is known as [Sign Magnitude](#sign-magnitude). However, the common encoding is [two's complement](#twos-complement).

### Two's Complement

- [ ] how to convert between x and -x easily ... or intuitively ... like fast -1 * x implementation?

The most significant bit is negative value, i.e. for `w` bits, when `bits[w-1]` is 0, the actual value is `-2^(w-1) + rest`.
Value range is `[-2^(w-1), 2^(w-1) - 1]`.

Example 4 bit signed integer

- `0000` is `0 + 0 + 0 + 0` = `0`
- `1000` is `-8 + 0 + 0 + 0` = `-8`
- `1001` is `-8 + 0 + 0 + 1` = `-7`
- `0111` is `0 + 4 + 2 + 1` = `7`

### Sign Magnitude

Sign Magnitude uses the first bit as the sign. The main problem of it is the encoding is not bijection,
i.e. there is more than one encoding that maps to 0. For example, `0000` is `0`, `1000` is also `0` (`-0`).
This is not the case in two's complement, `1000` is `-8` instead of `-0`, `0000` is the only encoding for `0`.

## Convert Signed and Unsigned

- [ ] does go behave the same?
- https://golang.org/ref/spec#Conversions Conversions between numeric types

When converting between signed and unsigned with same size, the underlying bits are not changed.
Only the interpretation changed, i.e. no data lose.

Signed to Unsigned

- if x > 0, same
- if x < 0, `x + 2^w` (where w is number of bits)

Unsigned to Signed

- if first bit is 0, same, i.e. `x < 2^(w-1)`
- if first bit is 1, `x - 2^w`

## Expand and Truncate

- [ ] 2.2.6 and 2.2.7 of csapp
