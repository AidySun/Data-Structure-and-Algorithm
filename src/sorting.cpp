#include <iostream>
#include <string>
#include "printA.h"

namespace Sorting {
    using namespace std;

    void bubble_sort(int *a, int n) {
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (a[i] > a[j]) {
                    int t = a[j];
                    a[j] = a[i];
                    a[i] = t;
                }
            }
        }
        printA(a, n);
    }

    void select_sort(int *a, int n) {
        for (int i = 0; i < n-1; i++) {
            int ci = a[i];
            int m_pos = i;
            for (int j = i+1; j < n; j++) {
                if (a[j] < a[m_pos]) {
                    m_pos = j;
                }
                a[i] = a[m_pos];
                a[m_pos] = ci;
            }
        }
        printA(a, n);
    }

    void insert_sort(int *a, int n) {

        for (int i = 1; i < n; i++) {
            int v = a[i];
            int j = i;
            for (; j > 0 && a[j-1] > v; j--) {
                a[j] = a[j-1];
            }
            a[i] = a[j];
            a[j] = v;
        }
        printA(a, n);
    }
}

int main() {
    using namespace Sorting;
    
    int n = 11;
    int a[] = {9, 2, 5, 1, 8, 5, 7, 3, 4, 0, 6};

    bubble_sort(a, n);
    select_sort(a, n);
    insert_sort(a, n);

    return 1;
}

