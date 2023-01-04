/*
Given a list intervals of n intervals, the ith element [s, e, p] denotes the starting point s, ending point e, and the profit p 
earned by choosing the ith interval. Find the maximum profit one can achieve by choosing a subset of non-overlapping intervals.

Two intervals [s1, e1, p1] and [s2, e2, p2] are said to be non-overlapping if [e1 <= s2] and [s1 < s2].



Example 1:
Input:
n = 3
intervals = {
{1, 2, 4},
{1, 5, 7},
{2, 4, 4}
}
Output:
8
Explanation:
One can choose intervals [1, 2, 4] and [2, 4, 4] for a 
profit of 8.


Example 2:
Input:
n = 3
intervals = {
{1, 4, 4},
{2, 3, 7},
{2, 3, 4}
}
Output:
7
Explanation:
One can choose interval [2, 3, 7] for a profit of 7.
Your Task:

You don't need to print or output anything. Complete the function maximum_profit() which takes an integer n and a 2D integer array intervals
and returns an integer, denoting the maximum profit which one can get by choosing the non-overlapping intervals.

Constraints:

1 <= n and n <= 104
1 <= starting point of ith interval < ending point of ith interval <= 105
1 <= profit earned by choosing ith interval <= 105
*/


class Solution {

  public:

    int f(int idx, vector<vector<int>> &intervals,int n, vector<int> &dp, vector<int> &start){

        if(idx>=n)
           return 0;
        if(dp[idx]!=-1) 
           return dp[idx];

        int index = lower_bound(start.begin(),start.end(),intervals[idx][1]) - start.begin();
        int take = intervals[idx][2] + f(index,intervals,n,dp,start);
        int nottake = f(idx+1,intervals,n,dp,start);

        return dp[idx] = max(take,nottake);

    }

    

    

    int maximum_profit(int n, vector<vector<int>> &intervals) {

        sort(intervals.begin(),intervals.end());
        vector<int>start;
        for(int i=0;i<n;i++){
            start.push_back(intervals[i][0]);
        }

        vector<int> dp(n+1,-1);

        return f(0,intervals,n,dp,start);

    }

};
