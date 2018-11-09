Data Structure and Algorighm
====

Regression
----

*Issues:*

* Invocation depth may cause stack overflow
  * set max depth
* Repeated calculation (e.g. fibonacci(4) and fibonacci(5))
  * cache calculated values
* Circle invocation
  * TBD

Queue
---

* Unlock Queue
* CAS(check and set/swap):

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
    } while ( cas(p, oldp, item) == false );
    cas (tail, oldp, item);
}
```

* CAS has ABA problem
* Circle queue

