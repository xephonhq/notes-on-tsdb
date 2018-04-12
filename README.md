# Notes on Time Series Database

**Deprecated**, please see related section

This a notes about the history and implementation of [various time series databases](https://github.com/xephonhq/awesome-time-series-database).
It aims to provide a deep insight of how various TSDBs work and how they evolve into current stage.
Also some related fields like mining time series data would be covered.

There are two versions:
  - a [Gitbook version](https://at15.gitbooks.io/notes-on-tsdb/content/)
  - a [Tex version](https://github.com/xephonhq/notes-on-tsdb/blob/master/tex).

For comparing TSDBs, you may want to try [Xephon-B](https://github.com/xephonhq/xephon-b) (still work in progress).

## Roadmap

The writing roadmap is based on my personal interest and need for course projects,
so it may not be in a well organized order.

- [ ] Basic knowledge of databases
- [ ] In memory time series databases
  - [ ] compress data (delta)
  - [ ] concurrency in single machine
  - [ ] handling meta data
  - [ ] log
  - [ ] multiple machine
- [ ] Query Language
- [ ] Benchmark
  - [ ] work load generation
  - [ ] existing tools and pitfalls
  - [ ] design of [Xephon-B](https://github.com/xephonhq/xephon-b)
- [ ] Genetic and time series
  - [ ] existing genetic databases
  - [ ] store genetic data in time series databases
  - [ ] mining genetic data (also see mining time series data)
- [ ] Mining time series data

## Related

- [at15/papers-i-read](https://github.com/at15/papers-i-read)
- [at15/code-i-read](https://github.com/at15/code-i-read)
- [at15/pub](https://github.com/at15/pub)

## Acknowledgment

- [Zheyuan Chen](https://github.com/czheo) for his participation in [Xephon-B](https://github.com/xephonhq/xephon-b)
- Prof. Alvaro for his [distributed system class](https://github.com/palvaro/CMPS232-Fall16)

## License

[CC BY-NC-SA 3.0](https://creativecommons.org/licenses/by-nc-sa/3.0/us/)
