
#include "stdafx.h"
#include <iostream>
#include "timer.h"

using namespace std;

/*
rm ./quick.out ; g++ QuickSort.cpp -o quick.out && ./quick.out
*/
// Array based
class Solution {
public:

    static void printA(int *a, int n) {
        for (int i = 0; i < n; i++) {
            cout<<a[i] << " ";
        }
        cout << "\n";
    }

    static void sortArray(int* a, int n, int& switchTimes)
    {
        quickSort(a, 0, n-1);
    }

    static void quickSort(int *a, int s, int e)
    {
        //cout <<"s ,e = " << s << ", " << e << "\n";
        if (s >= e) return;

        int m = partition(a, s, e);

        quickSort(a, s, m-1);
        quickSort(a, m+1, e);
    }

    static int partition(int *a, int l, int r) 
    {
        int guard = a[r];
        int m = l;

        for (int i = l; i < r; i++) {
            if (a[i] <= guard) {
                int n = a[i];
                a[i] = a[m];
                a[m++] = n;
            }
        }
        a[r] = a[m];
        a[m] = guard;

        return m;
    }

};

int main() {
	{
    Timer t("quick");

    for (int i = 0; i < 5000; i++) 
    {
        {
            int switchTimes;
            int a[10] = {4, 1, 9, 5, 2, 3, 8, 1, 0, 7};
            Solution::sortArray(a, 10, switchTimes);
        }

        {
            int switchTimes;
            int a[10] = {9,8,7,6,5,4,3,2,1,0};
            Solution::sortArray(a, 10, switchTimes);
        }
        {
            int switchTimes;
            int a[10] = {0,1,2,3,4,5,10,7,8,9};
            Solution::sortArray(a, 10, switchTimes);
        }
    }
    }
	system("pause");
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
