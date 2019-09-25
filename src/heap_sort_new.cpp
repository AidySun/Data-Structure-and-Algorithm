
/*   
g++ --std=c++11 hs.cpp

*/


#include <iostream>
#include <string>

using namespace std;

void printA(int a[], int n, string msg="") {
    cout << msg << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}



void heapify_up_to_down(int a[], int s, int e) {
    int maxI = s;

    int maxV = a[maxI];
    if (2*s+1 < e && a[2*s+1] > maxV) { 
        maxI  = 2*s+1;
        maxV = a[maxI];
    }
    if (2*s+2 < e && a[2*s+2] > maxV) { 
        maxI  = 2*s+2;
        maxV = a[maxI];
    }
    if (s == maxI) return;

    int t = a[s];
    a[s] = maxV;
    a[maxI] = t;

    heapify_up_to_down(a, maxI, e);
}



void heap_init(int a[], int n) {
    for (int i = n/2; i >= 0; i--) {
        heapify_up_to_down(a, i, n);
    }
}


void heap_sort(int a[], int n)
{
    int e = n;

    while (e != 1) {
        int t = a[0];
        a[0] = a[e-1];
        a[e-1] = t;

        heapify_up_to_down(a, 0, e-1);
        e = e-1;
    }
}

void hs(int a[], int n) {
    heap_init(a, n);
    printA(a, n, "after init:");

    heap_sort(a, n);
    printA(a, n, "after sort:");
}

int main() {
    int a[] = {6, 2, 7, 1, 3, 9, 0, 12, 55, 5};
    int n = sizeof(a)/sizeof(int);
    cout << "n = " << n << endl;
    printA(a, n, "original:");

    hs(a, n);

    return 0;
}

