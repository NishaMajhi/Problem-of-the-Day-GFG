/*
Given a matrix as 2D array. Find the reverse spiral traversal of the matrix. 


Example 1:
Input: R = 3, C = 3
  a = {{9, 8, 7},
       {6, 5, 4},
       {3, 2, 1}}
Output: 5 6 3 2 1 4 7 8 9
Explanation: Spiral form of the matrix
in reverse order starts from the centre 
and goes outward.


Example 2:
Input: R = 4, C = 4 
  a = {{1, 2, 3, 4},
       {5, 6, 7, 8},
       {9, 10, 11, 12}, 
       {13, 14, 15, 16}}
Output: 10 11 7 6 5 9 13 14 15 16 12 8 4 3 2 1
Explanation: 


Your Task:  
You dont need to read input or print anything. Complete the function reverseSpiral()
which takes R, C and a as input parameters and returns the matrix in reverse spiral form.

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(R*C)

Constraints:
1 <= R,C <=100
1 <= a[R][C] <=100
*/


class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
     
        vector<int> ans;
        int startingrow=0;
        int startingcol =0;
        int endingrow= R-1;
        int endingcol = C-1;
        int total = R*C;
        int count =0;
        
        
        /* we wil store all data in anticlock wise manner then we reverse it */
        
        //this is the most easiest solution, we have solved it in 4 part, each part is similar
        
        
        while(count<total){
            //for starting row
            for(int i= startingcol; i<=endingcol && count<total ; i++){
              ans.push_back(a[startingrow][i]); 
              count++;
            }
            startingrow++;
            
            //for ending column
            for(int i=startingrow ; count<total && i<=endingrow; i++){
                ans.push_back(a[i][endingcol]);
                count++;
            }
            endingcol--;
            
            //for ending row
            for(int i=endingcol ; count<total && i>=startingcol ; i--){
                ans.push_back(a[endingrow][i]);
                count++;
            }
            endingrow--;
            
            //for starting col
            for(int i = endingrow; count<total && i>=startingrow ;i--){
                ans.push_back(a[i][startingcol]);
                count++;
            }
            startingcol++;
        }
        
       int start =0; 
       int end = ans.size() -1;
       while(start <end){
           swap(ans[start++] , ans[end--]);
           
       }
       
       return ans;
    }
};
