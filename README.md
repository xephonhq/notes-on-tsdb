# Notes on Time Series Database

This is a work in progress book about time series database (TSDB) that contains:

- Survey on [various existing time series databases](https://github.com/xephonhq/awesome-time-series-database)
- How to write a (distributed) time series database from scratch.
- Related fields like distributed tracing, OLAP database.

## Roadmap

Merge survey in other repo

- [ ] [libtsdb-go](https://github.com/libtsdb/libtsdb-go)
- [ ] [xephon-k](https://github.com/xephonhq/xephon-k)
- [ ] [xephon-b](https://github.com/xephonhq/xephon-b)

Layout would be (subject to change, and need to merge w/ layout in libtsdb-go)

- 01 Overview
  - time series data
- 02 Basic
  - integer, float number and their machine representation (basic for working on compression)
  - statistic, distribution, random etc.
  - maybe information theory
- 03 components
  - overview
  - query language
    - complex query execution would also be interesting
    - SQL
    - continuous query, prometheus ppl also has an article about it
  - index (in memory and on disk?)
  - compression
  - storage
    - different backend, pros and cons
  - distribution
- 04 survey
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
- 05 benchmark
  - components
    - workload generator
    - stats collector
    - basic math, distribution
    - historgram and lhdr (forgot what's the name ...)
  - existing tools, their pro can cons
- 06 application
  - iot
  - monitoring  
- 07 analysis (a.k.a ml a.k.a import ts as tf)
  - prediction
  - anomaly detection
- 08 tracing (keep it in this repo for now)
- 09 OLAP, MPP
- 10 How we (or maybe just me...) built Xephon-K (not yet)
  - failure injection and correctness validation
  - continuous benchmark

## Related

- [Awesome Time Series Database](https://github.com/xephonhq/awesome-time-series-database)
- [libtsdb](https://github.com/libtsdb)

## Acknowledgment

- [Zheyuan Chen](https://github.com/czheo) for his participation in [Xephon-B](https://github.com/xephonhq/xephon-b)
- Prof. Alvaro for his [distributed system class](https://github.com/palvaro/CMPS232-Fall16)

## License

[CC BY-NC-SA 3.0](https://creativecommons.org/licenses/by-nc-sa/3.0/us/)
