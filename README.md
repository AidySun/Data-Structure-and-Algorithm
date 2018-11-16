Data Structure and Algorighm
====

Complexity
---
* Asympototic time complexity
  * `O(1) < O(logn) < O(n) < O(n\*logn) < O(n^2) < O(n^3) < O(2^n) < O(n!)`
* Asympototic space complexity

Recursion
----
*Issues:*
* Invocation depth may cause stack overflow
  * set max depth
  * munally stack management, do not use system's stack
* Repeated calculation (e.g. `fibonacci(4)` and `fibonacci(5)`)
  * cache calculated values
* Circle invocation
  * TBD

Queue
---
* Unlock Queue
* Circle queue

CAS & ABA
---
### CAS(check and set/swap):
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

    cas (tail, oldp, item);
}
```

* CAS has ABA problem

### ABA
Solutions:
  1. Deferred reclamation to avoid memory reuse (delete and new again to same address)
    * garbage collection, like Java.
  2. Adding a "tag" or "stamp" to distinguish status of pointer/memory. 
     They would be different if tag/stamp is different, eventhough value is the same.

Sorting
---

### Bubble Sort
* `T(n) = O(n^2)`
  * 满有序度 : `n*(n-1)/2`
  * 逆序度 = 满有序度 - 有序度
  * 逆序度 即 交换次数
* Sorted in place _[space complexity O(1)]_
* Stable _[means relative order of same values won't be changed]_
  * usage : sorted by more than two attributes _[e.g. orders sorted by time and price]_

### Insertion Sort
Sorted and unsorted parts, insert first unsorted to sorted part.
* Time complexity : `O(n^2)`
* Sorted in place 
* Stable

## Shell's Sort
**TODO**

### Selection Sort
Sorted and un-sorted parts, each loop selects smallest item from un-sorted and append to the end of sorted part.
* Time complexity : `O(n^2)`
* Sorted in place
* Unstable

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
Their `T(n) = O(n)` and no-comparison between data.

* Bucket Sort (桶排序)
  * data can be splitted to some buckets
  * suitable for data from disk
* Counting Sort
  * specific bucket sort, put same value in one bucket
  * data value's range shoud be contable (not very big)
* Radix sort (基数排序)
  * Using bucket or counting sorting
  * Multiple times
























