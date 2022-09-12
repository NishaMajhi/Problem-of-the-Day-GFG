/*
Given a matrix of size n*m. Every cell of matrix contains either 'A' or 'B'.
Exchange is defined as swaping the characters between two cells.
Your task is to find the minimum number of exchange needed to rearrange the given matrix such that no adjacent cell contains the same characters.
Two cells are adjacent if they share one of their common sides (left,right,front or back if exists). 
 

Example 1:

Input: matrix = {{A,A,B,A},{B,A,B,A},{B,B,A,B}}
Output: 4
Explanation: Minimum number of students whose 
sets got changed are 4 (indexes: ((0,1),(0,2),
(0,3),(2,0))). The final alloted sets are:
A B A B
B A B A
A B A B



Example 2:

Input: matrix = {{A,B},{B,A}}
Output: 0
Explanation: No two adjacent cell contains same
character.
 

Your Task:
You don' t need to read or print anything. 
Your task is to complete the function MinimumExchange() which takes matrix as input parameter and returns minimum number of  exchange needed.
 

Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(1)
 

Constraints:
1 <= n, m <= 100
*/



class Solution {
public:
int MinimumExchange(vector<vector<char>>matrix){
    
    int count1 = 0,count2 = 0;
    char ch;
    for(int i=0;i<matrix.size();i++){
        if(i%2 == 0)
           ch = 'A';
        else
           ch = 'B';
        for(int j=0;j<matrix[0].size();j++){
           if(matrix[i][j] != ch){
                 count1++;
            }
            if(ch == 'A')
              ch = 'B';
            else
              ch = 'A';
        }
    }
    for(int i=0;i<matrix.size();i++){
        if(i%2 == 0)
           ch = 'B';
        else
           ch = 'A';
        for(int j=0;j<matrix[0].size();j++){
           if(matrix[i][j] != ch){
                 count2++;
            }
            if(ch == 'B')
              ch = 'A';
            else
              ch = 'B';
        }
    }
    return min(count1,count2);
 }

};
