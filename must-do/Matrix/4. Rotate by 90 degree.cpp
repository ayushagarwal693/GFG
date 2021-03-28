/*
Rotate by 90 degree
===================

Given a square matrix[][] of size N x N. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

Example 1:

Input:
N = 3
matrix[][] = [[1 2 3],
              [4 5 6],
              [7 8 9]]
Output:
3 6 9 
2 5 8 
1 4 7
Your Task:
You only need to implement the given function rotate(). Do not read input, instead use the arguments given in the function. 

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 50
1 <= matrix[][] <= 100

*/
  
//====================================================================================================================
  
  
  void transpose(vector<vector<int>> &matrix, int n)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
   
    void rotate(vector<vector<int> >& matrix) 
        { 
            int n = matrix.size();
            transpose(matrix, n);
            for(int i=0;i<n;i++)
            {   int low = 0, high = n-1;
                while(low<high)
                {
                    swap(matrix[low][i], matrix[high][i]);
                    low++;
                    high--;
                }
            }
        } 
