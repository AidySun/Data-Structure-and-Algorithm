#include <string>
#include <iostream>
#include <queue>

using namespace std;


/*
NOTE: heap array's real data is from index 1, parameter n is number of real data, where length(a) = n+1
*/

void printHeap(int *a, int n) {
    queue<int> q;
    q.push(a[1]);
    int index = 1;
    while (!q.empty()) {
        cout << "\n";
        int l = q.size();
        for (int i = 0; i < l; i++) {
            cout << q.front() << "  " ;
            if (q.front() != -1) {
                int child = 2*index;
                if (child <= n) q.push(a[child]); else q.push(-1);
                if ((child + 1) <= n) q.push(a[child + 1]); else q.push(-1);
            }
            index++;
            q.pop();
        }
    }
}

void heapity_bottom_to_top(int *a, int n, int i) {
    while (i/2 > 0) {
        if (a[i] > a[i/2]) {
            swap(a[i], a[i/2]);
        }
        i = i/2;
    }
}

void heapity_top_to_bottom(int *a, int s, int n) {
    while (s <= n) {
        int c = s*2;
        int maxIndex = s;

        if (c <= n && a[c] > a[maxIndex]) maxIndex = c;
        if (c+1 <= n && a[c+1] > a[maxIndex]) maxIndex = c+1;
        if (maxIndex == s) return;

        swap(a[maxIndex], a[s]);
        s = maxIndex;
    }
}

void buildHeap(int *a, int n) {

    int i = 1;
    while(i <= n) {
        heapity_bottom_to_top(a, n, i);
        i++;
    }
}

void buildHeap2(int *a, int n) {
    int i = n/2;

    while(i > 0) {
        heapity_top_to_bottom(a, i, n);
        i--;
    }
}
void heapSort(int *a, int n) {
    for (int i = n; i > 0; i--) {
        swap(a[1], a[i]);
        heapity_top_to_bottom(a, 1, i-1);
    }
}

int main() {
    int n = 10;
    int a[] = {-1, 4, 1, 9, 5, 6, 2, 3, 7, 0, 8};
    printHeap(a, 10);
    buildHeap2(a, 10);
    printHeap(a, 10);
    heapSort(a, 10);
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout<<a[i] << " ";
    }

}
