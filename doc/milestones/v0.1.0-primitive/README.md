# v0.1.0 Primitive

## Motivation

Have a good understand of layout and int and float. Explain what happens when converting one to another.
Might cover gauge, histogram etc. as well.

## Specs

Able to answer the following questions and provides self contained code snippet in Go, C and Rust.

- endianness, cpu and network
- int, unsigned int, what happens when converting
- float IEEE, converting float to uint64 (i.e. why not do a cast directly like int and uint)
- counter & gauge
- histogram, how to determine bucket, long hdr (forgot the actual name)

## Components

### Endianness

- most CPU uses little endian, and network is big endian
  - how to valid this, especially on network side
- hexdump

### Int

Merging notes from libtsdb and CSAPP

- signed integer, two's complement
- converting
- overflow

### Float

Flush notes from CSAPP

- IEEE
- converting to int (only saw this in Go, not sure about other languages)

### Gauge

- check if there is any official definitions

### Histogram

- fixed bucket
- dynamic bucket
- long tail? (there is a talk from Zing JVM, a java library, I suppose a go library as well)