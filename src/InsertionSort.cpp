
#include <iostream>
#include "timer.h"
using namespace std;

/*
rm ./insertion.out ; g++ InsertionSort.cpp -o insertion.out && ./insertion.out
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

    static void sortArray(int* a, int n, int& switchTimes) {
        switchTimes = 0;

        for (int i = 1; i < n; i++) {
            int val = a[i];
            int j = i;
            while (j > 0 && a[j-1] > val) {
                switchTimes++;
                a[j] = a[j-1];
                j--;
            }
            a[j] = val;
        }
    }
};

int main() {
    Timer t("insertion");

    for (int i = 0; i < 500; i++) {
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
// List based
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (NULL == head || NULL == head->next) return head;
        ListNode preHead(0);
        preHead.next = head; 

        ListNode *end = NULL;

        while(end != preHead.next->next){
            ListNode *pre = &preHead;
            while (pre->next->next != end) {
                if (pre->next->val > pre->next->next->val) {
                    ListNode *p = pre->next;
                    pre->next = p->next;
                    p->next = pre->next->next;
                    pre->next->next = p;
                }
                pre = pre->next;
            }
            end = pre->next;
        }
        return preHead.next;
    }
};
*/
