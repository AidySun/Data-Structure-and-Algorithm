
#include <iostream>
#include "timer.h"

using namespace std;

/*
rm ./merge.out ; g++ MergeSort.cpp -o merge.out && ./merge.out
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
        sortArrayInRange(a, 0, n-1);
    }

    static void sortArrayInRange(int *a, int s, int e)
    {
        //cout <<"s ,e = " << s << ", " << e << "\n";
        if (s >= e) return;

        int m = (s+e)/2;
        sortArrayInRange(a, s, m);
        sortArrayInRange(a, m+1, e);

        merge(a, s, e);
    }

    static void merge(int *a, int s, int e) 
    {
        //cout<<"merging " << s << ", " << e << "\n";
        int * temp = new int[e-s+1];

        int m = (s+e)/2;
        int i = s, j = m+1;
        int n = 0;
        while(i <= m && j <= e) {
            if (a[i] <= a[j]) {
                temp[n++] = a[i++];
            } else {
                temp[n++] = a[j++];
            }
        }
        while (i<=m) temp[n++] = a[i++];
        while (j<=e) temp[n++] = a[j++];

        for (int ii = s; ii <= e; ii++) {
            a[ii] = temp[ii-s];
        }
        delete []temp;
        temp = NULL;
    }


};

int main() {
    Timer t("merge");

    for (int i = 0; i < 500; i++) 
    {
        {
            int switchTimes;
            int a[10] = {4, 1, 9, 5, 2, 3, 8, 1, 0, 7};
            //Solution::printA(a, 10);
            Solution::sortArray(a, 10, switchTimes);
            //Solution::printA(a, 10);
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
