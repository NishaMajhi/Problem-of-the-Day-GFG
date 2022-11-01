/*
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.


Example 1:
Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 


Example 2:
Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives 
us {1,2,3}. Hence, 2 is median.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() 
which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)


Constraints:
1 <= R, C <= 400
1 <= matrix[i][j] <= 2000
*/



class Solution{   
public:
     int cntsmall(vector<int>mat,int mid,int C){
        int start = 0,end = C;
        while(start<end){
            int m = start+(end-start)/2;
            if(mat[m]<=mid){
                start = m+1;
            }
            else{
                end = m;
            }
        }
        return start;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here      
        int start = INT_MAX,end = INT_MIN;
        for(int i = 0; i<R; i++){
            start = min(start,matrix[i][0]);
            end = max(end,matrix[i][C-1]);
        }
        int req = (R*C+1)/2;
        while(start<end){
            int mid = start+(end-start)/2,smaller = 0;
            for(int i = 0; i<R; i++){
                smaller+=cntsmall(matrix[i],mid,C);
            }
            if(smaller<req){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        return start;
    }
};
