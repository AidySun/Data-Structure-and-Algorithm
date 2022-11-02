# System Design

1. [Availability](#availability)
   1. [fail-over](#fail-over)
   2. [replication](#replication)
2. [Scalability](#scalability)
         1. [Scalability v.s. Performance](#scalability-vs-performance)
         2. [Scalability v.s. Extensibility](#scalability-vs-extensibility)
3. [Database](#database)
   1. [RDBMS (Relational Database Management System)](#rdbms-relational-database-management-system)
      1. [How to scale](#how-to-scale)
         1. [master-slave](#master-slave)
         2. [master-master](#master-master)
         3. [Replication](#replication-1)
      2. [Federation](#federation)
   2. [SQL vs NoSQL](#sql-vs-nosql)
4. [Load Balancer](#load-balancer)
5. [Reverse Proxy](#reverse-proxy)
   1. [Reverse Proxy vs Load balancer](#reverse-proxy-vs-load-balancer)
6. [System Design Interview by Alex xu.pdf](#system-design-interview-by-alex-xupdf)



- scalability
- stability
- availability
- consistency

- Everything is a trade-off

- CAP theorem (in a **distributed computer system**)
  - consistency: each read gets the most recent write, or error
  - availability: a non-failing request receives a response (no error, no timeout)
  - partition tolerance: system continues to operate 

## Availability

- two patterns to support high availability
  - fail-over
  - replication

### fail-over

### replication




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

##### Scalability v.s. Performance

- performance issue means the system is slow for a single user.
- scalability problem means the system is fast for single user, but slow for heavy load.

##### Scalability v.s. Extensibility
  - scalability : ability to handle a growing amount of work, 
    - generally means reduplication(repeat) of same system/server.
  - extensibility : system design principle, to provide for change - typically enhancements - while minimizing impact to existing system.
    - generally means to add new functionality / component to system


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
- slave(s): readonly, master replicates writes to slave
- disadvantage of master-slave
  - refer to _disadvantage of replication_ in [RDBMS-replication](#replication-1)

##### master-master

- disadvantage of master-master
  - a load balancer (or app modification) is needed to distribute requests to diff servers
  - most master-master either loosely consistence or increased write latency due to synchronization
  - refer to _disadvantage of replication_ in [RDBMS-replication](#replication-1)

##### Replication

- disadvantage of replication
  - potential loss of data if master fails before new written data is replicated
  - data writes in master are replicated to read servers, may slow down reads

#### Federation

- (or functional partitioning) splits up DB by functions
- disadvantage
  - joining data from two DBs is more complex with a server link

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

## Load Balancer

- it's web server pool
- balance methods
  - random
  - least loaded
  - round robin (with weight)
  - hash
  - session/cookies
  - layer 4 (transport layer)
  - layer 7 (application layer)

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

- load balancer used when there are multiple servers provide same services

- Nginx load balancer sample
  ```
  upstream my_server_pool {
    server 192.168.1.2:8080;
    server 192.168.2.3:8080;
    server abc.com:8080 weight = 2;
    ip_hash; // server select algorithm
 
  }
  server {
    listen 80;
    location / {
        pass_proxy http://my_server_pool;
    }
  }
  ```

- Nginx reverse proxy sample
  ```
  location ~ /vod/ {
    proxy_pass  http://127.0.0.1:8081
  }
  ```


## System Design Interview by Alex xu.pdf

- DNS


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


