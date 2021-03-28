/*
Smallest Positive missing number
================================

Given an array arr[] of size N, find the smallest positive number missing from the array.

 

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing
number is 6.
 

Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
 

Your Task:
You don't need to read input or print anything. The task is to complete the function findMissing() which takes arr and N as input parameters and returns the smallest positive missing number.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 106
-106 <= arr[i] <= 106

*/
   
  int findMissing(int arr[], int n) { 
        
        const int N = 1e6 + 2;
        bool check[N];
        for(int i=0;i<N;i++)
            check[i] = false;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=0)
                check[arr[i]] = true;
        }
        for(int i=1;i<N;i++)
        {
            if(check[i]==false)
            return i;
        }
    }
