#include <iostream>

static void printA(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout<<a[i] << " ";
        if (i%20 == 0) cout << endl;
    }
    cout << "\n";
}