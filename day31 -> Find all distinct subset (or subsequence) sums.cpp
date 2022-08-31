/*
Given a set of integers, find all distinct sums that can be generated from the subsets of the given sets.
 

Example 1:

Input: nums = {1,2}
Output: {0,1,2,3}
Explanation: Four distinct sums can be
calculated which are 0, 1, 2 and 3.
0 if we do not choose any number.
1 if we choose only 1.
2 if we choose only 2.
3 if we choose 1 and 2.



Example 2:

Input: nums = {1,2,3}
Output: {0,1,2,3,4,5,6}
Explanation: Seven distinct sum can be calculated
which are 0, 1, 2, 3, 4, 5 and 6.
0 if we do not choose any number.
1 if we choose only 1.
2 if we choose only 2.
3 if we choose only 3.
4 if we choose 1 and 3.
5 if we choose 2 and 3.
6 if we choose 1, 2 and 3.

 

Your Task:
You don't need to read or print anything
. Your task is to complete the function DistinictSum() which takes nums as input parameter and
returns a list containing the distinict sum in increasing order,
 

Expected Time Complexity: O(n * sum) where sum = sum of all elements of nums.
Expected Space Complexity: O(n * sum)
 

Constraints:
1 <= length of nums <= 102
1 <= nums[i] <= 102
*/


class Solution {
public:

   vector<int> DistinctSum(vector<int>nums){
	    int sum = 0;
	    for(auto &e : nums){
	        sum += e;
	    }
	    int n = nums.size();
	    vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1, false));
	    for(int i = 0; i <= n; i++){
	        dp[i][0] = true;
	    }
	    for(int i = 1; i <= sum; i++){
	        dp[0][i] = false;
	    }
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j <= sum; j++){
	            dp[i][j] = dp[i - 1][j];
	            if(j - nums[i - 1] >= 0 && dp[i - 1][j - nums[i - 1]] == true){
	                dp[i][j] = true;
	            }
	        }
	    }
	    vector<int> ans;
	    for(int i = 0; i <= sum; i++){
	        if(dp[n][i]){
	            ans.push_back(i);
	        }
	    }
	    return ans;
	}
};
