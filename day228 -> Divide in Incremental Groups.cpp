/*
Given two integers N and K, the task is to count the number of ways to divide N into K groups of positive integers 
such that their sum is N and the number of elements in groups follows a non-decreasing order (i.e. group[i] <= group[i+1]).



Example 1:
Input:
N = 8
K = 4
Output:
5
Explanation:
There are 5 groups such that their sum is 8 
and the number of positive integers in each 
group is 4. The 5 groups are [1, 1, 1, 5], 
[1, 1, 2, 4], [1, 1, 3, 3], [1, 2, 2, 3] and 
[2, 2, 2, 2].



Example 2:
Input: 
N = 4
K = 3
Output:
1
Explanation: 
The only possible grouping is {1, 1, 2}. Hence,
the answer is 1 in this case.


Your Task:
Complete the function countWaystoDivide() which takes the integers N and K as the input parameters,
and returns the number of ways to divide the sum N into K groups.

Expected Time Complexity: O(N2*K)
Expected Auxiliary Space: O(N2*K)

Constraints:
1 ≤ K ≤ N ≤ 100
*/


class Solution {
private:
    int solve(int i, int N, int K, vector<vector<vector<int>>> &dp) {
        
        if(N == 0 && K == 0) {
            return 1;
        }
        if(K == 0 || N == 0) {
            return 0;
        }
        
        if(dp[i][N][K] != -1) {
            return dp[i][N][K];
        }
        
        int ans = 0;
        for(int j = i; j <= N; j++) {
            ans += solve(j, N-j, K-1, dp);
        }
        return dp[i][N][K] = ans;
    }

public:
    int countWaystoDivide(int N, int K) {
        
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(K+1, -1)));
        return solve(1, N, K, dp);
    }
};
