#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
rm bs.out ; g++ -std=c++14 binary_search.cpp -o bs.out && ./bs.out
*/

/* return index of v, -1 if not found

Precondition: no ducplication
*/
int bs_array_loop(int *a, int n, int v) {
    int l = 0, h = n-1;

    while (l <= h) {
        int m = (h-l)/2 + l;
        if (a[m] == v) {
            return m;
        } else if (a[m] < v) {
            l = m+1;
        } else {
            h = m-1;
        }
    }
    return -1;
}

int bs_array_recursion(int *a, int l, int h, int v) {
    if (l>h) return -1;

    int m = (h-l)/2 + l;
    if (a[m] == v) return m;
    if (a[m] < v) return bs_array_recursion(a, m+1, h, v);
    else return bs_array_recursion(a, l, m-1, v);
}

int bs_array_recursion(int *a, int n, int v) {
    return bs_array_recursion(a, 0, n-1, v);
}


int main() {
    static const int N = 100;
    int data[N] = {0};
    for (auto i = 0; i < N; i++) {
        data[i] = i*2 + 1;
    }

    {
        int i1 = bs_array_recursion(data, N, 3);
        cout << "position of 3 is : " << i1 << "\n";
    }
    
    {
        int i1 = bs_array_recursion(data, N, 199);
        cout << "position of 199 is : " << i1 << "\n";
    }
    return 0;
}



