# Data Structure & Algorithm

1. [Data Structure and Algorithm](#data-structure-and-algorithm)
   1. [OVERVIEW](#overview)
         1. [Coding Tips :beers:](#coding-tips-beers)
         2. [Complexity](#complexity)
         3. [Recursion](#recursion)
         4. [Queue](#queue)
         5. [CAS \& ABA](#cas--aba)
         6. [Bubble Sort](#bubble-sort)
         7. [Insertion Sort](#insertion-sort)
         8. [Shell's Sort](#shells-sort)
         9. [Selection Sort](#selection-sort)
         10. [Merge Sort](#merge-sort)
         11. [Quick Sort](#quick-sort)
         12. [Other](#other)
         13. [Summary](#summary)
         14. [Hash Function](#hash-function)
   2. [HASHING](#hashing)
         1. [Requirement](#requirement)
         2. [Usages](#usages)
   3. [BINARY TREE](#binary-tree)
         1. [Binary Search Tree (BST)](#binary-search-tree-bst)
         2. [Balance Binary Search Tree 平衡二叉查找树](#balance-binary-search-tree-平衡二叉查找树)
         3. [Red-black Tree](#red-black-tree)
         4. [递归树](#递归树)
         5. [Sorted Array v.s. Hash Table v.s. Tree :beers:](#sorted-array-vs-hash-table-vs-tree-beers)
         6. [HEAP](#heap-1)
         7. [Storage](#storage)
         8. [Heapify](#heapify)
   4. [HEAP SORTING](#heap-sorting)
         1. [How to strote a graph](#how-to-strote-a-graph)
   5. [Topo Sort](#topo-sort)
         1. [DFS \& BFS](#dfs--bfs)
   6. [Dijkstra 最短路径算法](#dijkstra-最短路径算法)
   7. [TODO](#todo)
   8. [Bloom Filter](#bloom-filter)
   9. [BF](#bf)
   10. [RK](#rk)
   11. [BM (Moyer-Moore)](#bm-moyer-moore)
   12. [English](#english)

## Data Structure and Algorithm

### OVERVIEW

<image src="images/MindMap.jpg" height="360" />

##### Coding Tips :beers:

* `int m = (low + high) / 2;` has the overflow issue. Solutions:
```CPP
    int m = (high - low) / 2 + low;
    // or 
    int m = ((high - low) >> 1) + low;
```

* modulo of two nums
```Java
// calculate the index of key
index = key.hash & (capicity - 1);
// which is equal to
index = key.hash % capicity;
```


##### Complexity
* Asymptotic space complexity
* Asymptotic time complexity
  * `O(1) < O(logn) < O(n) < O(n*logn) < O(n^2) < O(n^3) < O(2^n) < O(n!)`
  <img src="images/time complexity.jpg" height="360" />

> 时间复杂度并不能完全代表代码的执行时间。
> 大 O 时间复杂度表示法，会忽略掉常数、系数和低阶，并且统计的对象是语句的频度。
> 不同的语句，执行时间也是不同的。时间复杂度只是表示执行时间随数据规模的变化趋势，
> 并不能度量在特定的数据规模下，代码执行时间的多少。

##### Recursion
*Issues:*
* Invocation depth may cause stack overflow
  * set max depth
  * manually stack management, do not use system's call stack
* Repeated calculation (e.g. `fibonacci(4)` and `fibonacci(5)`)
  * cache calculated values
* Circle invocation
  * TBD

##### Queue
* Unlock Queue
* Circle queue

##### CAS & ABA
CAS is used for lock-free implementation.

####### CAS(check and set/swap):
```C
bool cas(int* p, int oldv, int newv) {
    if (*p == oldv) {
        *p = newv;
        return true;
    }
    return false;
}
```

* EnQueue with CAS:
```C
EnQueue(x) {
    item = new record()
    item->value = x;
    item->next = NULL
  
    p = tail;
    oldp = p;

    do {
        while (p->next != NULL)
            p = p->next;
    } while ( cas(p->next, NULL, item) == false );

    // set tail if it still points to oldp
    // it could fail because other process/thread might has updated tail already
    cas(tail, oldp, item);
}
```

* CAS has ABA problem

####### ABA
Solutions:
  1. Deferred reclamation to avoid memory reuse (delete and new again to same address)
    * garbage collection, like Java.
  2. Adding a "tag" or "stamp" to distinguish status of pointer/memory. 
     They would be different if tag/stamp is different, eventhough value is the same.


# SORTING


##### [Bubble Sort](./src/BubbleSort.cpp)
* `T(n) = O(n^2)`
  * 满有序度 : `n*(n-1)/2`
  * `逆序度 = 满有序度 - 有序度`
  * 逆序度 即 交换次数
* Sorted in place _[space complexity O(1)]_
* Stable _[means relative order of same values won't be changed]_
  * usage : sorted by more than two attributes _[e.g. orders sorted by time and price]_

##### [Insertion Sort](./src/InsertionSort.cpp)
Sorted and unsorted parts, insert first unsorted to sorted part.
* Time complexity : `O(n^2)`
* Sorted in place 
* Stable

##### Shell's Sort
**TODO**

##### [Selection Sort](./src/SelectionSort.cpp)
Sorted and un-sorted parts, each loop selects smallest item from un-sorted and ~append to~ switch with the end of sorted part.
* Time complexity : `O(n^2)`
* Sorted in place
* Unstable _[because of the switch]_

##### [Merge Sort](./src/MergeSort.cpp)
Using recursion to split sorting items and sort them independently, then merge those sorted items to be one.
* Time complexity : `O(n*logn)` _[stable TC, no matter best, worst]_
* Space complexity: `O(n)` 
  * _[occurred in `merge()`, no more than n]_
* Stable sorting
* **NOT** in-place _[memory required]_

##### [Quick Sort](./src/QuickSort.cpp)
Find a guard and put smaller to left, bigger to right (refer to `partition()` function). Recursion.
* Time complexity : `O(n*logn)`
  * worst `T(n) = O(n^2)` _[when guard cannot split list properly]_
* Space complexity : `O(1)`
* **Unstable**
* In-place
* Guard choosing to avoid worst TC:
  * random
  * pick multiple (more than 3) and select the middle one or average value

##### Other
They are `T(n) = O(n)` and no-comparison between data.

* Bucket Sort (桶排序)
  * data can be spited to some buckets
  * suitable for data from disk
* Counting Sort
  * specific bucket sort, put same value in one bucket
  * data value's range should be countable (not very big)
* Radix sort (基数排序)
  * Using bucket or counting sorting
  * Multiple times

##### Summary
  * `O(n^2)` Sortings are rearly used in reality
  * Quick sort vs Merge sort
    * Quick sort has `O(n^2)` complexity in the worth, whilc Merge sort has stable `O(n*logn)`
    * Merge sort has space complexity 
  * Quick sort (together with merge sort) is popular
    * `qsort()` in C is implemented with quick sort and merge sort
    * sort in Java is implemented with [heap sort](#heap-sort)


# [BINARY SEARCHING](./src/binary_search.cpp)

* `TC = O(logn)`
  * `O(logn)` sometimes even be better than `O(1)`, e.g. N is very large.

**Preconditions:**
  * data is sorted
  * array based
    * large size/amount data may not be suitable, since large contiguous memory is required.
  * data is not dynamic changed
    * if it is dynamic, it either makes it ordered when changing data, or sort the data before search.

  * Most problems with binary search can be replaced with Binary Tree and Hash Table.
    * but the problems like finding 1st great or equal value.

[Homework: `sqrt()` using binary search](./src/binary_search_sqrt.cpp)

# HASH TABLE

* Array-based - random access
* Load Factor = (num of existed item) / (len of hash table)
  * default is 0.75 in Java
* capacity is better to be 2^n (bitwise operation can be used instead of modulo operator)
  ```Java
  int index = hashvalue & (capicity - 1);
  ```

##### Hash Function
* Requriements
  * generates a non-negative integer
  * if key1 == key2 then hash(key1) == hash(key2)
  * if key1 != key2 then hash(key1) != hash(key2)

####### Hash conflict
* **Open addressing**
  * Linear probing (`O(n)`)
    * 插入时 - 如果位置被占用，依次向后查找空闲位置
    * 查找时 - 比较散列值位置的元素，若不相等，依次向后查找, 直到空闲位置
      * 到空闲位置停止有数据丢失问题，可以将删除的数据标记为deleted，而不是真正删除
  * Double hashing 双重散列
    * a group of hash function is used, 对冲突的数据使用不同hash function
  * Quadratic probing 二次探测
    * 探测步长为二次方，e.g. hash(key)+0, hash(key)+1^2, hash(key)+2^2...
* **Chaining**
  * conflicted items are stored in a linked chain in same hashed value

####### Dynamic Expansion
动态扩容后（2倍 in Java），数据如果一次性迁移会有performance issue。可以把数据迁移分担到每次数据操作。
E.g.新表中中的每次写入都从旧表中迁移一条数据。查询时，想从新表查找，不存在再查找旧表。

### HASHING

##### Requirement
* Input cannot be calculated from output
* Input sensitive - tiny diff in input would cause huge diff in output
* Low conflict
* High performance

##### Usages
1. 安全加密 Encryption 
  * MD5. (MessagebDigest Algorithm) - 128 bits, unsecured
  * SHA (Secure Hash Algorithm)
  * DES (Data Encryption Standard)
  * AES (Advanced Encryption Standard)
  * 对于存储的hash密码，为防止字典攻击，应该使用Salt盐
2. 唯一标示 Uniformity 
  * e.g. Image - 文件大，我们可以取摘要，如开头、中间、末尾各取100字节, 再对相同hash的数据做全量对比
3. 数据校验
4. 散列函数
5. 负载均衡
  * 对于session sticky，即长连接，可以对IP或session ID做hashing，然后与server数量取模
6. 数据分片
  * MapReduce的基本设计思想
  * 取一条数据(e.g. 日志中的单词)做hash，与server num取模，相同数据会分配到同一server
7. 分布式存储
  * Cache集群动态扩容，若hash值整体变更会发生雪崩效应。
    * Consistent Hashing - 一致性Hash (每次添加或删除cache node只有小范围影响)

# SKIP LIST

* TC: `O(logn)`
  * **for search, insert and delete**
* skip list uses Random Function to keeps its balance
  * add inserted data as indexes to layers generated by Random Function
* Skip list vs Red Black Tree  
  * _Why Redis uses skip list (and hash table) as its sorted list, but not red-black tree?_
  * skip list and RBT are all for eays query/insert/delete 
  * **skip list is good for range search, which is better than RBT**
  * implementation of skip list is easier than RBT
  * skip list is more flex (by changing its index strategy)
  * RBT is earlier than SL, many `Map` type is implemented with RBT

# TREE

- BFS: Breadth First Search
- DFS: Depth First Search
* To implement DFS/BFS with loop instead of recursion:
  * Stack (FILO) is used for DFS
  * Queue (FIFO) is used for BFS

### BINARY TREE

* 表示方式
  * 链式 : 最常用
  * 数组 ：根节点从1开始，对于第k个节点，2k为其左子节点，2k+1为右子节点
* 二叉树遍历TC : `O(n)`
* 遍历方式
  * preOrder - `self -> left -> right`
  * inOrder - `left -> self -> right`
  * postOrder - `left -> right -> self`
  * 按层
* Complete Binary Tree 完全二叉树
  * for a BT with k layers, 1~k-1 layers have full nodes, nodes in layer k are continuous from left to right.
  * 适合数组存储

##### Binary Search Tree (BST)
* Any node is larger than ALL its left children, and smaller than ALL its right children. 
* TC : `O(logn)` _[same with the height of tree]_
* 删除
  * 标记为已删除，不真正删除
  * 有两个节点时，从右子树找最小值来替换
* 插入时对于相同值
  * 存在右子节点
  * 存在同一节点（链式）
* 二叉查找树的高度可能超过logn，而导致时间复杂度退化(最坏会退化成链表)。平衡二叉查找树可解决此问题。

##### Balance Binary Search Tree 平衡二叉查找树
* 任何节点左右子树高度差不大于1
  * 实际应用可能会超过1， 相对平衡
* 满二叉树、完全二叉树为平衡二叉树，非完全二叉树有可能是平衡二叉树 (左子树为空，右子树非空)
* AVL Tree
* Red-black tree 最为著名

##### Red-black Tree 
* High performance to search, insert and delete
* Height of RBT is about `2 * logn`
* Skip List could be an alternateness of RBT
  * Skip list has easier implementation than RBT
  * Redis uses Skip List as sorted set

##### 递归树
* 1个细胞的生命周期是3小时，1小时分裂一次，求N小时后有多少细胞。

##### Sorted Array v.s. Hash Table v.s. Tree :beers:

* Sorted Array
>   * good for sorted data
>   * good for range query
>   * not good for insertion (dynamic data)

* Hash Table
>   * Good for **fixed value data**
>   * Not good for sorted data
>   * Not good for range query
>   * Hash table doesn't have stable performance
>     * Although hash table has time complexity `O(1)`, it may be slower than binary searching tree's `O(logn)`. 
>   * Hash table is more complex than binary search tree
>     * Because hash table needs time for hash function, handle hash conflict, dynamic expansion and shrinkage.

* Tree
>   * good for dynamic data
>   * good for range query
>   * good for sorted data


# [HEAP](./src/HeapSort.cpp)

* [BinaryHeap.cpp](https://gist.github.com/AidySun/66c92ac88455288fa629a844413c598e)

##### HEAP
* Heap is complete binary tree.
* Value of a node is >= (big heading) or <= (small heading) than its children.
* complete binary tree is suitable to be stored in array

##### Storage
* The root index starts from `1`.
* For the node with index `i`, its left child index would be `2 * i`, and right child is `2 * i + 1`
* In array, the storage starts from 1 as well. That mean the index 0 in array is not used.

##### Heapify
`O(logn)`
* Top to Bottom
  * starts from root, find largest child greater than self, and switch, repeat
* Bottom to Top
  * switch with parent if it is greater than self, repeat

####### Heap Deletion 
0. Delete the node from tree directly would bring *hole* to the tree, following approach would be better:
1. Switch node with the last element
2. Delete last
3. Heapify node from top to bottom

####### Heap Insertion 
1. Append new item to end
2. Heapify node from bottom to top

####### Heap Usage
* Top `k` data
* `k%` value (e.g. middle value of a number sequence)
  * two heap, one stores `k% * n` using big heading, and the other stores `(1-k%) * n` with small heading
  * new value compaires with two root nodes to deceide which heap to insert
  * balance two heap after insert/delete

### HEAP SORTING
* TC = `O(n*logn)`
* Sorted in place
* Unstable

1. Build heap `O(n)`
  * Parse data from `1 to n` (begin to end). Insert each data. 
  * Parse data from `n/2 to 1`, heapify each node from top to bottom.
    * because, for a **complete binary tree**, data `n/2+1 to n` are leaf nodes at the beginning.
    * and leaf nodes do NOT to heapify, since they would be heapified when heapifying nodes from `n/2 to 1`
    * that is, heapify from `height-1` to `root`
  
2. Sorting `O(n*logn)`
   * Top to bottom- same as deletion

> Q: Why quick sorting is more popular than heap sorting?
> A: 1) quick sort access data in order, heap sort is not. Not good for CPU caching.
>    2) heap sort has more switch times. Sorted data became unsorted after heap creation.


# GRAPH

* Consistent of vertex and edge.
  * Directed graph - degree _(number of edges)_
  * Undirected graph - in-degree / out-degree
  * Weighted graph - each edge has its weight

##### How to strote a graph
1. Adjacency Matrix 
    * Two degree arrays
    * Pros
      * Simple, directly
      * easy for matrix-based calculation
    * Cons
       * waste space
         * especially for Sparse Matrix (稀疏矩阵)
2. Adjancency List
    * Hash table with linked list
    * Less space than Adjacency Matrix but more time
      * Balance Binary Tree or Red-black Tree instead of linked list

### Topo Sort


- algorithm:
  - find vertexes with 0 indegree
  - find those verex connect by edges, with indegree -1
  - remove 0-indegree vertex
  - repeat

- 应用于 有向无环图 (DAG: Directed acyclic graph)
- Kahn: find all items with 0 input count, remove them and decrease its dependencies input count.
- DFS: visited adj, inverse adjacent, visit its array first, then self.

- 拓扑排序应用非常广泛，解决的问题的模型也非常一致。凡是需要通过局部顺序来推导全局顺序的，一般都能用拓扑排序来解决。除此之外，拓扑排序还能检测图中环的存在。对于 Kahn 算法来说，如果最后输出出来的顶点个数，少于图中顶点个数，图中还有入度不是 0 的顶点，那就说明，图中存在环。

##### DFS & BFS

- DFS
  - detect cycle in directed graph
    - idea: find *back edge* (one vertex's edge to itself or one of its ancesters)
    ```
    // store graph in adj matrix
    // visited array for all vertex
    enum Status {
      Unvisited,
      Visting,
      Visted 
    };

    for (v: all vertices) {
      if (v.status == Unvisited) {
        dfs(vertex)
      }
    }
    bool dfs(vertex) {
      v.status = Visting
      for (w: adj[vertex]) {
        if (w.status == Unvisited && dfs(w)) { // circle detected 1
          return true
        } else if (w.status == Visting) { // circle detected 2
          return true
        }
      }
      v.status = Visited
    }
    ```
- BFS
  #. detect cycle in directed graph
    ```
    vector<int> indegree(N, 0); // this is a simple case that each vertex has int value, so it uses index as key here, for complex type, a map/hashtable is needed?
    // calculate indegree of each vertex
    queue<Vertex> q;
    // find vertices with 0 indegree and add to q
    int visitedCount = 0;
    while (!q.empty()) {
      visitedCount++;
      for (w: adj[q.top]) {
        if (--indegree[w] == 0) {
          q.push_back(w);
        }
      }
    }

    if (visitedCount != N) {
      // circle detected
    }

    ```
  #. detect cycle in undirected graph
    ```

    ```


### Dijkstra 最短路径算法

- 最短路径算法，更加准确地说，是单源最短路径算法（一个顶点到一个顶点）。提到最短路径算法，最出名的莫过于 Dijkstra 算法了。
  - 有向带权图

# BIT MAP
* A special kind of *Hash Table*.

### TODO

### Bloom Filter
* Based on Bit Map


# String Matching

### BF

* `O(m*n)`

### RK

* To match `m` length substring in `n` length string, `(n-m+1)` possible substrings
* calculate hash value of all possible substring
* compare hash value to match

### BM (Moyer-Moore)

* [Reference](http://www.cs.jhu.edu/~langmea/resources/lecture_notes/boyer_moore.pdf)
* bad char
* good suffix

* it's better than BMP algorithm



### English

- `interactively` and `recursively`























