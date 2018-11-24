Data Structure and Algorighm
====

### Coding Tips
* `int m = (low + high) / 2;` has the overflow issue. Solutions:
```CPP
    int m = (high - low) / 2 + low;
    // or 
    int m = ((high - low) >> 1) + low;
```

### Complexity
* Asympototic time complexity
  * `O(1) < O(logn) < O(n) < O(n*logn) < O(n^2) < O(n^3) < O(2^n) < O(n!)`
* Asympototic space complexity

### Recursion
*Issues:*
* Invocation depth may cause stack overflow
  * set max depth
  * munally stack management, do not use system's call stack
* Repeated calculation (e.g. `fibonacci(4)` and `fibonacci(5)`)
  * cache calculated values
* Circle invocation
  * TBD

### Queue
* Unlock Queue
* Circle queue

### CAS & ABA
CAS is used for lock-free implementation.

#### CAS(check and set/swap):
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

#### ABA
Solutions:
  1. Deferred reclamation to avoid memory reuse (delete and new again to same address)
    * garbage collection, like Java.
  2. Adding a "tag" or "stamp" to distinguish status of pointer/memory. 
     They would be different if tag/stamp is different, eventhough value is the same.


SORTING
----

### Bubble Sort
* `T(n) = O(n^2)`
  * 满有序度 : `n*(n-1)/2`
  * `逆序度 = 满有序度 - 有序度`
  * 逆序度 即 交换次数
* Sorted in place _[space complexity O(1)]_
* Stable _[means relative order of same values won't be changed]_
  * usage : sorted by more than two attributes _[e.g. orders sorted by time and price]_

### Insertion Sort
Sorted and unsorted parts, insert first unsorted to sorted part.
* Time complexity : `O(n^2)`
* Sorted in place 
* Stable

### Shell's Sort
**TODO**

### Selection Sort
Sorted and un-sorted parts, each loop selects smallest item from un-sorted and ~append to~ switch with the end of sorted part.
* Time complexity : `O(n^2)`
* Sorted in place
* Unstable _[because of the switch]_

### Merge Sort
Using recursion to split sorting items and sort them indenpendently, then merge those sorted items to be one.
* Time complexity : `O(n*logn)` _[stable TC, no matter best, worst]_
* Space complexity: `O(n)` 
  * _[occurred in `merge()`, no more than n]_
* Stable sorting
* **NOT** in-place _[memory required]_

### Quick Sort
Find a guard and put smaller to left, bigger to right (refer to `partition()` function). Recursion.
* Time complexity : `O(n*logn)`
  * worst `T(n) = O(n^2)` _[when guard cannot split list properly]_
* Space complexity : `O(1)`
* Unstable
* In-place
* Guard choosing to avoid worst TC:
  * random
  * pick multiple (more than 3) and select the middle one or average value

### Other
They are `T(n) = O(n)` and no-comparison between data.

* Bucket Sort (桶排序)
  * data can be splitted to some buckets
  * suitable for data from disk
* Counting Sort
  * specific bucket sort, put same value in one bucket
  * data value's range shoud be contable (not very big)
* Radix sort (基数排序)
  * Using bucket or counting sorting
  * Multiple times


BINARY SEARCHING
----
* `TC = O(logn)`
  * `O(logn)` sometimes even be better than `O(1)`, e.g. N is very large.

**Preconditions:**
  * data is sorted
  * array based
    * large size/amount data may not be suitable, since large contiguous memory is required.
  * data is not dynamic changed
    * if it is dynamic, it either makes it ordered when changing data, or sort the data before search.

  * Most problems with binary search can be replaced with Binary Tree and Hash Table.
    * but the problems like finding 1st great or eaual value.

HASH TABLE
---
* Array-based - random access
* Load Factor = (num of existed item) / (len of hash table)

### Hash Function
* Requriements
  * generates a non-nagative integer
  * if key1 == key2 then hash(key1) == hash(key2)
  * if key1 != key2 then hash(key1) != hash(key2)

#### Hash confliction
  * **Open addressin**
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

HASHING
---
### Requirement
* Input cannot be calculated from output
* Input sensitive - tiny diff in input would cause huge diff in output
* Low confliction
* High performance

### Usages
1. 安全加密 Encryption 
  * MD5 (Message-Digest Algorithm) - 128 bits, unsecury
  * SHA (Secure Hash Algorithm)
  * DES (Data Encryption Standard)
  * AES (Advanced Encryption Standard)
  * 对于存储的hash密码，为防止字典攻击，应该使用Salt盐
2. 唯一标示 Uniformity 
  * e.g. Image - 文件大，我们可以取摘要，如开头、中间、末尾各取100字节, 再对相同hash的数据做全量对比
3. 数据校验
4. 散列函数
5. 负载均衡
6. 数据分片
7. 分布式存储





















