/*
Give a N * N square matrix A, return all the elements of its anti-diagonals from top to bottom.



Example 1:
Input: 
N = 2
A = [[1, 2],
     [3, 4]]
Output:
1 2 3 4
Explanation: 

Hence, elements will be returned in the 
order {1, 2, 3, 4}.



Example 2:
Input: 
N = 3 
A = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
Output: 
1 2 4 3 5 7 6 8 9
Explanation: 

Hence, elements will be returned in 
the order {1, 2, 4, 3, 5, 7, 6, 8, 9}.


Your Task:
You don't need to read input or print anything. Your task is to complete the function downwardDigonal() 
which takes an integer N and a 2D matrix A[ ][ ] as input parameters and
returns the list of all elements of its anti-diagonals from top to bottom.

Expected Time Complexity: O(N*N)
Expected Auxillary Space: O(N*N)

Constraints:
1 ≤ N, M ≤ 103
0 ≤ A[i][j] ≤ 106
*/

class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A){

        // Your code goes here
        vector<int>ans;
        for(int j=0;j<N;j++){
            int i=0;
            int temp=j;
            while(temp>=0){
               ans.push_back(A[i][temp]);
               i++;
               temp--;
            }
        }

        for(int i=1;i<N;i++){
            int j=N-1;
            int temp=i;
            while(temp<N){
              ans.push_back(A[temp][j]);
              temp++;
              j--;
            }
        }

        return ans;

    }

};
