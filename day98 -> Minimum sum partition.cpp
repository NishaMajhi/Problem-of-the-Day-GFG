/*
Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 and S2 
such that the absolute difference between their sums is minimum and find the minimum difference


Example 1:
Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   



Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

Your Task:  
You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters
and returns the integer value


Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)


Constraints:
1 ≤ N*|sum of array elements| ≤ 106
0 < arr[i] <= 105
*/


class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    
	    int totalSum = 0;
        for(int i=0;i<n;i++)totalSum+=nums[i];
        
        vector<vector<bool>> dp(n+1,vector<bool>(totalSum+1,false));
        
        for(int i=0;i<n;i++) dp[i][0] = true;
        dp[0][nums[0]] = true;
        
        // 0 is already covered in the base case
        for(int ind=1;ind<n;ind++) //in the recursion call we went from n-1 to 0
        {
            // 0 is already covered in the base case
            for(int target = 1 ; target<=totalSum; target++)  //in the recur call we went from sum to 0
            {
                // copy the recurrance
                bool take = false;
                if(target>=nums[ind])
                {
                    take = dp[ind-1][target-nums[ind]];
                }
                
                bool notTake = dp[ind-1][target];
                
                dp[ind][target] = take || notTake;
            }
        }
        
        // int the last row of dp , we have the info whether that sum is possible or not
        int ans = 1e9;
        for(int j=0;j<=(totalSum)/2;j++)
        {
            if(dp[n-1][j] == true)  //that sum is possible
            {
                int sum1 = j;
                int sum2 = totalSum-j;
                ans = min(ans,abs(sum1-sum2));
            }
        }
        
        return ans;
	    
	    
	} 
  
};
