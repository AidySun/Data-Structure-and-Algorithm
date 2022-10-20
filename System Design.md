
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


## SQL vs NoSQL

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











