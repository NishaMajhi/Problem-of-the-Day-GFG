/*
You are given N balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array arr.
You are asked to brust all the balloons.
If you brust the ith  balloon,, you will get arr[ i - 1 ] * arr[ i ] * arr[ i + 1] coins. 
If i - 1, or i + 1 goes out of bounds of the array, consider it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by brusting the balloons wisely.



Example 1:

Input:
N = 4
arr[ ] = {3, 1, 5, 8}
Output: 167
Explanation: 
arr[ ] = {3, 1, 5, 8}  - - > {3, 5, 8} - - > {3, 8} - - > { 8} - -> { }
coins = 3 *1 *5,      +      3*5*8     +   1*3*8   +  1*8*1   = 167
 
 

Example 2:

Input:
N = 2
arr[ ] = {1, 10}
Output: 20
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes the array of integers arr and N as parameters
and returns the maximum coin you can collect.

Expected Time Complexity: O(N*N*N)
Expected Auxiliary Space: O(N*N)

Constraints:
1 ≤ N ≤ 300
0 ≤ arr [ i ]  ≤ 100
*/



class Solution {
public:
    int maxCoins(int n, vector<int> &a) {
        a.push_back(1);
        a.insert(a.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        int maxi=INT_MIN;
        for(int i=n;i>=1;i--){
            for(int j=1; j<=n;j++){
                if(i>j) continue;
                maxi = INT_MIN;
                for(int idx=i;idx<=j;idx++){
                    int cost=a[i-1]*a[idx]*a[j+1]+dp[idx+1][j]+dp[i][idx-1];
                    maxi=max(cost,maxi);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    } 
};
