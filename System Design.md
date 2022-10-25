# System Design

1. [Scalability](#scalability)
2. [Database](#database)
   1. [RDBMS (Relational Database Management System)](#rdbms-relational-database-management-system)
      1. [How to scale](#how-to-scale)
         1. [master-slave](#master-slave)
   2. [SQL vs NoSQL](#sql-vs-nosql)
3. [Reverse Proxy](#reverse-proxy)
   1. [Reverse Proxy vs Load balancer](#reverse-proxy-vs-load-balancer)
4. [System Design Interview by Alex xu.pdf](#system-design-interview-by-alex-xupdf)

## Scalability

- https://www.allthingsdistributed.com/2006/03/a_word_on_scalability.html
  - ~Def~ when we increase the resources in a system, it results in increased performance in a manner proportional to resources added.
    - increasing performance:
      - in general means serving more units of work
      - it can also be to handle larger units/mount of work/data
  - Scalability is not the only case to "add more resources". Some other reasons like reliability (introducing redundancy to make system *always-on*).
  - *Why scalability is so hard?*
    - it must be defined in advance, it cannot be an after-thought. Make sure adding resources actually results performance improvement, not adversely affected.
    - when hardware(mostly) changes/upgrades in some nodes, make sure the performance is not affect and new resources are not underutilized. Because some algorithms rely on *uniformity*.
    - *Solution*
      - the system should take scalability into account.
      - inspect key direction the system goes.
      - architecture could handle heterogeneity (diff hardware)

## Database

### RDBMS (Relational Database Management System)

- AICD
  - Atomic: each transaction is all or nothing.
  - Isolation: transactions got same result no matter they are run serially or concurrently.
  - Consistency: any transaction will bring DB from one state to another.
  - Durability: once a transaction is committed/executed successfully, it remains so.

#### How to scale
  - master-slave replication
  - master-master replication
  - sharding(分片)
  - federation(联合)
  - denormalization(反格式化)
  - SQL tuning

##### master-slave

- master : read and write
- slave(s): readonly
- master replicate writings to slave(s), in kind of tree structure

### SQL vs NoSQL

- SQL
  - structured data
  - strict schema
  - relational data
  - need for complex joins
  - transactions
  - clear patterns for scaling
  - lookups by index are very fast
 
- NoSQL
  - semi-structured data
  - dynamic or flexible schema
  - no-relational data
  - no need for complex joins
  - store many data (TB, PB)
  - very data intensive workload
  - very high throughput for IOPS


## Reverse Proxy

It's a **web server* that centralizes internal services and provides unified interfaces to the public.

- Benefits
  - security - hide backend servers
  - scalability & flexibility - clients only see reverse proxy
  - SSL termination - decrypt income requests and encrypt responses, so backend servers don't to perform those expensive operations.
  - compression - response
  - caching
  - static content server

- Disadvantages
  - increased complexity
  - single point failure. config multiple reverse proxy (e.g. failover)increases complexity

### Reverse Proxy vs Load balancer


## System Design Interview by Alex xu.pdf

- DNS

- load balancer
  - web server pool

- database tier
  - replication
    - master-slave(s)
    - master-master
    - *TODO*: how to avoid data loss

- `------ above is solid serer and DB tiers, next is to improve load/response time`

- CDN: content delivery network
  - run by third party providers, users get content from closest CDN
  - static content
  - also can be dynamic content caching
    - e.g. HTML pages based on request path
  - TTL : time to live

- cache tier
  - layer between application server and DB
  - read-through cache: not exist, get from DB and save as cached
  - challenge: how to keep consistency between cache and DB
    - https://efficientcodeblog.wordpress.com/2017/11/05/how-facebook-scale-memcache/#:~:text=Facebook%20used%20memcached%20as%20a%20building%20block%20to,to%20a%20shared%20storage%20pool%20at%20low%20cost.
  - SPOF: single point of failure
  - Eviction policy: LRU (last recently used)


- `------ next is to consider scaling web tier horizontally`

- stateless web server
  - for stateful server, it could work by making load balancer route same user to same server, but that is not perfect solution, e.g. it has problems when adding/deleting server.
  - get rid of session (by storing sessions in DB or other persistent storage, web server can access)
    - more simpler, more robust, and scalable


