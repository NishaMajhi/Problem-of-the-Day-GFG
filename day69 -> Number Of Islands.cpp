/*
You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. 
Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. 
The array has k operator and each operator has two integer A[i][0], A[i][1] means
that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island.
Return how many island are there in the matrix after each operator.
You need to return an array of size k. 


Example 1:
Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}
Output: 1 1 2 2

Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
 

 

Example 2:
Input: n = 4
m = 5
k = 4
A = {{0,0},{1,1},{2,2},{3,3}}
Output: 1 2 3 4

Explanation:
0.  00000
    00000
    00000
    00000
1.  10000
    00000
    00000
    00000
2.  10000
    01000
    00000
    00000
3.  10000
    01000
    00100
    00000
4.  10000
    01000
    00100
    00010
 

Your Task:
You don't need to read or print anything. Your task is to complete the function numOfIslands()
which takes an integer n denoting no. of rows in the matrix, an integer m denoting the number of columns in the matrix 
and a 2D array of size k denoting  the number of operators.

Expected Time Complexity: O(m * n)
Expected Auxiliary Space: O(m * n)

Constraints:

1 <= n,m <= 100
1 <= k <= 1000
*/



class Solution {
    int row[4] = {0, -1, 0, 1}, col[4] = {-1, 0, 1, 0};
    
  public:
  
    bool exist(int x, int y, int n, int m, vector<vector<int>>& copy){
        return (x >= 0 && y >= 0 && x < n && y < m && copy[x][y] == 1);
    }
    
    void dfs(int x, int y, int n, int m, vector<vector<int>>& island){
        island[x][y] = 0;
        for(int k=0;k<4;k++){
            int x_ = x+row[k], y_ = y+col[k];
            if(exist(x_, y_, n, m, island))     dfs(x_, y_, n, m, island);
        }
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>> island(n, vector<int>(m, 0));
        vector<int> res;
        int k = operators.size();
        
        for(int ind=0;ind<k;ind++){
            int x = operators[ind][0], y = operators[ind][1], cnt = 0; island[x][y] = 1;
            vector<vector<int>> copy = island;
            
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(copy[i][j] == 1)     cnt++, dfs(i, j, n, m, copy);
                }
            }
            res.push_back(cnt);
        }
        
        return res;
    }
};
