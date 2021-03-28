/*
 Merge Without Extra Space
 =========================
 
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
 

Example 1:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.
Example 2:

Input: 
n = 2, arr1[] = [10, 12] 
m = 3, arr2[] = [5 18 20]
Output: 
arr1[] = [5 10]
arr2[] = [12 18 20]
Explanation:
After merging two sorted arrays 
we get 5 10 12 18 20.


Your Task:
You don't need to read input or print anything. You only need to complete the function merge() that takes arr1, arr2, n and m as input parameters and modifies them in-place so that they look like the sorted merged array when concatenated.
 

Expected Time Complexity:  O((n+m) log(n+m))
Expected Auxilliary Space: O(1)
 

Constraints:
1 <= n, m <= 5*104
0 <= arr1i, arr2i <= 107

*/
  
  
  void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            for(int i=0;i<n;i++)
            {
                bool flag = false;
                if(arr1[i]>arr2[0])
                {
                    swap(arr1[i], arr2[0]);
                    flag = true;
                }
                if(flag)
                {
                    sort(arr2, arr2 + m);
                }
            }
        } 

/*=================================================================================================================*/


// Merging two sorted arrays with O(1)
// extra space
#include <bits/stdc++.h>
using namespace std;

// Function to find next gap.
int nextGap(int gap)
{
	if (gap <= 1)
		return 0;
	return (gap / 2) + (gap % 2);
}

void merge(int* arr1, int* arr2, int n, int m)
{
	int i, j, gap = n + m;
	for (gap = nextGap(gap);
		gap > 0; gap = nextGap(gap))
	{
		// comparing elements in the first array.
		for (i = 0; i + gap < n; i++)
			if (arr1[i] > arr1[i + gap])
				swap(arr1[i], arr1[i + gap]);

		// comparing elements in both arrays.
		for (j = gap > n ? gap - n : 0;
			i < n && j < m;
			i++, j++)
			if (arr1[i] > arr2[j])
				swap(arr1[i], arr2[j]);

		if (j < m) {
			// comparing elements in the second array.
			for (j = 0; j + gap < m; j++)
				if (arr2[j] > arr2[j + gap])
					swap(arr2[j], arr2[j + gap]);
		}
	}
}

// Driver code
int main()
{
	int a1[] = { 10, 27, 38, 43, 82 };
	int a2[] = { 3, 9 };
	int n = sizeof(a1) / sizeof(int);
	int m = sizeof(a2) / sizeof(int);

	// Function Call
	merge(a1, a2, n, m);

	printf("First Array: ");
	for (int i = 0; i < n; i++)
		printf("%d ", a1[i]);

	printf("\nSecond Array: ");
	for (int i = 0; i < m; i++)
		printf("%d ", a2[i]);
	printf("\n");
	return 0;
}
