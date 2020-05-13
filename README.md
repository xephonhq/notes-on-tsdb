# Notes on Time Series Database

This is a work in progress book that contains:

- Survey on [various existing time series databases](https://github.com/xephonhq/awesome-time-series-database)
- How to write a (distributed) time series database.
- Related fields like distributed tracing, OLAP database.

## Roadmap

Merge survey in other repo

- [ ] [libtsdb-go](https://github.com/libtsdb/libtsdb-go)
- [ ] [xephon-k](https://github.com/xephonhq/xephon-k)
- [ ] [xephon-b](https://github.com/xephonhq/xephon-b)

Layout would be (subject to change, and need to merge w/ layout in libtsdb-go)

- survey
  - influxdb
  - prometheus, victoriametrics, thanos (and another one ... forgot the name from weaveworks)
  - m3db
  - akumuli, btrdb (both are tree like)
  - timescaledb (and others on pg, most of them are dead so ...)
  - druid alike (linkedin also got one)
  - graphite (and newer backends)
  - mysql
  - elasticsearch
  - crate (it looks pretty good, though it seems it is bought by some other company)
- tsdb components
  - query language
    - complex query execution would also be interesting
  - index
  - compression
  - storage
    - different backend, pros and cons
  - distribution
- benchmark
  - workload generator
    - basic math, distribution
    - historgram and lhdr (forgot what's the name ...)
  - existing tools and pitfalls
- analysis (a.k.a ml a.k.a import ts as tf)
  - prediction
  - anomaly detection
- application
  - iot
  - monitoring
- tracing (keep it in this repo for now)

## Related

- [Awesome Time Series Database](https://github.com/xephonhq/awesome-time-series-database)
- [libtsdb](https://github.com/libtsdb)

## Acknowledgment

- [Zheyuan Chen](https://github.com/czheo) for his participation in [Xephon-B](https://github.com/xephonhq/xephon-b)
- Prof. Alvaro for his [distributed system class](https://github.com/palvaro/CMPS232-Fall16)

## License

[CC BY-NC-SA 3.0](https://creativecommons.org/licenses/by-nc-sa/3.0/us/)
