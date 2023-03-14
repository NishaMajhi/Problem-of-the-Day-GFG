/*
We have been given N balloons, each with a number of coins associated with it.
On bursting a balloon i, the number of coins gained is equal to A[i-1]*A[i]*A[i+1].
Also, balloons i-1 and i+1 now become adjacent. Find the maximum possible profit earned after bursting all the balloons. 
Assume an extra 1 at each boundary.



Example 1:
Input: 
N=2
a[]={5, 10}
Output: 
60
Explanation: First Burst 5, Coins = 1*5*10
              Then burst 10, Coins+= 1*10*1
              Total = 60



Example 2:
Input:
N=4
a[] = {3,1,5,8}
Output:
167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167.



Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes the array arr[],
its size N, and returns the maximum number of coins that can be collected.

Expected Time Complexity: O(N^3)
Expected Space Complexity: O(N^2)

Constraints:
1 <= N <= 400
0 <= a[i] <= 100
*/

class Solution{
    public:
        int maxCoins(int n, vector <int> &a)
        {
            int dp[n][n];
            for(int g=0; g<n; g++) {
                for(int i=0,j=g; j<n; i++,j++) {
                    int val = INT_MIN;
                    for(int k=i; k<=j; k++) {
                        int lft = k==i ? 0 : dp[i][k-1];
                        int rght = k==j ? 0 : dp[k+1][j];
                        int curr = a[k];
                        if(i-1>=0) curr *= a[i-1];
                        if(j+1<n) curr *= a[j+1];
                        val = max(val, lft + rght + curr);
                    }
                    dp[i][j] = val;
                }
            }
            return dp[0][n-1];
        }
};
