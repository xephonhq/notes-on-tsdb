# Log structured merge tree

<!-- toc -->

A lot of notes are from notes by Sreekanth[^1]

## Terminology

- TPC and YCSB
  - Transaction Processing Performance Council[^2] is the de facto benchmark for databases
  - YCSB is created for benchmarking large scale serving systems, i.e. HBase, Cassandra where TPC is not accurate and overkill
- Transaction logs
  - Used for durability, recovery from crash
  - WAL, WBL
  - [ ] TODO: LSM tree does not seems to be used with transaction logs
- BTrees
  - often mean B+ Trees
- Blocks
  - [ ] 'refers to the contents of one node in the B+ tree, A block in B+ tree contains the keys for guiding the search process'
  - [ ] 'And number size of block has is related to how tall the tree is going to be.'
    - this seems to be a typo
  - 'It has nothing to do with the disk blocks(sectors)'
- Pages
  - 'A smallest chunck of informaction db can work with'
  - 'Data in a db are kept in a series of pages that are mappted to the disk(sectors)'
  - 'A B tree will hold links to these pages'
  - 'Multiple pages can be resident on a single disk block (not the same block above)'
- Multi-page Blocks
  - ‘A Block that contains multiple pages and can be fit into a single read/write operations’
  - 'In LSM tree a block contains as many entires as can fit a disk block'
- Leaf nodes
  - ?'The pointer to the records on disk'?
    - [ ] NO, I think they should be the data
- Buffer (Manager)
  - 'All operation on pages happen in meory (i.e. search on record id/match record fileds)'
  - page in and out like OS does for virtual memory
- Records
- Merge
  - 'called **compaction** in some papers'
  - when one level reach its size threshold, it is merged to the next level, i.e. C_0 -> C_1, memory to disk

## History

- 'Everyone uses B Tree'
- 'Big Table came out and cited LSM trees'
- 'NoSql boom! And everybody wanted to build LSM'

Users

- Bigtable
- Cassandra
- HBase
- PNUTS
- LevelDB/RocksDB
- SQLite (optional)
- MongoDB
  - [ ] WiredTiger ?

## Slides summary

will be updated after reading other paper and slides ... (it's a merge process as well)

Why

- all write goes to memory
  - [ ] what if memory fails
- batched disk io
  - only merge process leads to disk writes
- all disk IO is sequential
  - always append only?
  - [ ] the empty and filling block part? how to garbage collect old blocks

Cons

- degraded read performance
  - need to scan all levels in general cases, i.e. for exact match and unique keys, just hit the memory is enough
  - 'sequential search is merge of all components'
    - [ ] TODO: isn't this duplicate with previous points
- Assumes clustered index
  - 'Works well for KV stores'
    - [ ] TODO: why KV, and I forgot what is clustered index
- Merge prcoess
  - 'Hard to get right' exactly
  - 'Causes trouble with Recovery methods'
    - [ ] The paper did mentioned recovery in section 4

Disk Model

- IOPS (Input/Output Operations per second) is important
- 'In place updates are always Random IO'
- 'Append only are generally Sequential IO'

![compare of random and seq access in db and ram](images/comparing random and sequential access in disk and memory.jpg)

**Comparing random and sequential access in disk and memory**[^3]

- [ ] the data for the image is quite old, the source is a 2009 book, where SSD is not advanced as today

Database Index

Example: `select * from employees where salary > 100`

- binary search, very slow

BTrees

- 'Balanced Binary Search Trees are greate in memory'
  - AVL/RB/2-3
  - the paper suggested AVL
- 'But leads to too much IO on a disk'

Btree of order m

- 'has m children'
- 'all leaves appear at the same level'
- non leaf node with k children has k-1 keys
- orders are high, > 100
- shallow
- root in memory
- insert/deletes are bit more expensive

B+ Tree
- make sequential access faster
  - 'double linked list for the leaf nodes'
  - 'all keys reside in the leaves'
  - 'inner nodes only act as guides'

LSM Tree

- '**Unlike Btree it's not a databstructure**'
- Fast write
  - [ ] TODO: blind write?
- 'Reasonable reads'  

**LSM Tree Ideas**

- 'All writes go to memory, and are buffered there'
- 'All writes are done on a disk block'
- 'Use memory optimized datastructures for memory （Hashes/Skiplists/RB trees)'
- 'All writes are append only'

- [ ] multiple memory components as well (only really useful for concurrency)

C_0

- 'use memory efficient RB/2-3/AVL trees'
- 'No need to have disk block sized'

C_1

- Uses B+ Tree
- 100% full nodes
- **Contiguous multi-page that matches disk blokcs**
  - [ ] that could be what the paper keep mentioning, multi-page

Merge

- **asynchronously** moves newly added items from C_0 to C_1 ... C_n
  - only move when one level can not hold anymore
- 'idea is to fill the C_1 block 100% before writing to disk'
- 'complicate than merge sort because pages that need to move to buffer on read of C_1 blocks'
  - [ ] TODO: typo? C_1 blocks need to be read to buffer before merge

- merge sort: **needs an extra array in memory**
- C_1 leaf is made buffer resident -> emptying block
- C_0 smallest leaves are merged
- into new C_1 leaf node -> filling block
  - [ ] TODO: block or disk block
- write to a new disk area
- [ ] TODO: **continue till emptying block is empty**
- [ ] TODO: NOTE: there is no FIFO(age related stuff here)
- [ ] TODO: sounds like CRDT

Find

skip

Delete

- Exact Match
  - Put a tombstone for the key
  - Merge process finds the acutal key and annhilates it
- Predicate delete
  - i.e. `DELETE FROM user WHERE age < 18`
  - Put a tombstone for a key matching a filter
    - [ ] TODO: put tombstone on key or make it a filter for future merge process
  - [ ] TODO: 'merge allows use to do some fancy things, like find-note(high latency full text search for example)'


Cost comparisions with BTree

- Multipage write
- Batching efficiency
- [ ] TODO: append only?

Concurrency

- 'Merge causes additional issues over C_0'
- [ ] 'The general approach is to skip these locked entries when merging'

Recovery

- every insert goes to the transaction log
  - [ ] TODO: is index really part of database? like when crash recovery, the index is also recovered
- check pointing
  - [ ] TODO: is check point mentioned in the paper?
  - Complete all merge operations
  - Write C_0 to disk (Stop the world)
    - [ ] TODO: leveldb have stall problem
  - Write the chekpoint log
    - Merge cursors
    - Component roots

Optimization

Faster read

- [ ] TODO: Differential Index
- Bloom filters
- [ ] TODO: Fractional Cascading

Faster Merges/Compactions

- [ ] TODO: Lock free
- Levels

Cassandra

The idea of Cassandra really explain this well

> Cassandra writes are first written to a commit log (for durability), and then to an in-memory table structure called a memtable. A write is successful once it is written to the commit log and memory, so there is very minimal disk I/O at the time of write. Writes are batched in memory and periodically written to disk to a persistent table structure called an SSTable (sorted string table).

- SSTables are backed by Bloomfilter (bLSM paper)
  - [ ] TODO: bloom filter
- https://wiki.apache.org/cassandra/MemtableSSTable
- https://wiki.apache.org/cassandra/ArchitectureSSTable

http://stackoverflow.com/questions/15857779/commitlog-and-sstables-in-cassandra-database

LevelDB

- [ ] TODO: Fixed size SSTables
- 'Each level is guaranteed to have unique keys'
- [ ] TODO: 'Each level is 10x size previous'
- [ ] TODO: 'SSTables are promoted to higher levels'
- [ ] TODO: 'Memtables are implemented by a skiplist'

## References

[^1]: [Notes for reading the LSTM tree paper](https://gist.github.com/sreeix/45aec4f51a3578a20700)
[^2]: [TPC Wiki](https://en.wikipedia.org/wiki/Transaction_Processing_Performance_Council)
[^3]: [The Pathologies of Big Data](http://queue.acm.org/detail.cfm?id=1563874)
