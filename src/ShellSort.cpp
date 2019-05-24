#include "stdafx.h"

#include <iostream>

#include "timer.h"
#include "printA.h"

using namespace std;

/*
rm ./shellsort.out ; g++ ShellSort.cpp -o shellsort.out && ./shellsort.out
*/

// Q: How to understand Shell Sort?
// A: It reduce inversion rate (???) with steps from big to small. 
//	  Big steps (e.g. Bubble Sort) reduce iversion rate by 1 each time.

class ShellSort 
{

    void swap(int* a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

	void printByLen(int* a, int n, int l) {
		cout << "step = " << l << "\n";

		for (int i = 0; i < n; i++) {
			cout << " " << a[i];
			if (((i+1) % l) == 0) cout << endl;
		}
		cout << endl;
	}

public:
    void sort(int* a, int n) 
    {
		int step = n / 2;

		while (step > 0) {

			// insertion sort to column
			for (int i = step; i < n; i++) {
				for (int j = i; j >= step && a[j] < a[j - step]; j -= step) {
					swap(a, j, j - step);
				}
			}


			step = step / 2;
		}
    }



	void sort2(int* arr, int len) {
		int gap, i, j;
		int temp;
		for (gap = len >> 1; gap > 0; gap >>= 1) {
			printf("---%d\n", gap);
			printByLen(arr, len, gap);
			for (i = gap; i < len; i++) {
				temp = arr[i];
				for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
					arr[j + gap] = arr[j];
				arr[j + gap] = temp;
				printByLen(arr, len, gap);
			}
		}
		printByLen(arr, len, len);
	}
};


int main() {
	{
		Timer t("shell");

		ShellSort s;

		for (int i = 0; i < 50000; i++) 
		{
			{
				int a[10] = { 4, 1, 9, 5, 2, 3, 8, 1, 0, 7 };
				s.sort(a, 10);
			}

			{
				int a[10] = { 9,8,7,6,5,4,3,2,1,0 };
				s.sort(a, 10);
			}
			{
				int a[10] = { 0,1,2,3,4,5,10,7,8,9 };
				s.sort(a, 10);
			}
		}
	}

	system("pause");
}