/*
You live in Geek land. Geek land can be seen as a grid of shape N x M.There are K enemy at K positions. 
Each enemy blocks the row and column to which it belongs. You have to find the largest continuous area that is not blocked.
No two enemies share the same row or the same column.

Example 1:

Input:
N = 2
M = 2
K = 1
enemy[]={{2,2}}
Output:
1
Explanation:
Since only (1,1) cell is free from the enemy hence answer is 1.
 

Example 2:

Input:
N = 3
M = 3
K = 1
enemy[]={{3,3}}
Output:
4
Explanation:
The cells (1,1),(1,2) ,(2,1) and (2,2) are free hence answer =4.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function largestArea() which 
takes the size of geek land n,m and a 2-D matrix enemy of size k denoting the coordinates of the enemy's and need to return the largest area that is free.

Expected Time Complexity: O(KlogK)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N,M <= 104
0<=K<=min(N,M)
1<=Xi<=N
1<=Yi<=M
*/


class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            vector<int>row(n,0);
            vector<int>col(m,0);
            
            for(int i = 0 ; i < enemy.size() ; i++){
                row[enemy[i][0]-1] = -1;
                col[enemy[i][1]-1] = -1;
            }
            
            
            int maxRow = 0;
            int maxCol = 0;
            int cntRow = 0;
            int cntCol = 0;
            
            for(int i = 0 ; i < n ; i++){
                if(row[i]!=-1){
                    cntRow++;
                }
                else{
                    cntRow = 0;
                }
                maxRow = max(maxRow,cntRow);
            }
            
            for(int i = 0 ; i < m ; i++){
                if(col[i]!=-1){
                    cntCol++;
                }
                else{
                    cntCol = 0;
                }
                maxCol = max(maxCol,cntCol);
            }
            
            return maxRow*maxCol;
        
        }
};
