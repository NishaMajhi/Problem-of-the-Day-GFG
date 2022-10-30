/*
Initially, the zoo have a single chick. A chick gives birth to 2 chicks every day and the life expectancy of a chick is 6 days.
Zoo officials want to buy food for chicks so they want to know the number of chicks on an Nth day. Help the officials with this task.
 


Example 1:

Input: N = 2 
Output: 3
Explanation: First day there is only 1 chick.
On second day total number of chicks = 3. 



Example 2:

Input: N = 3
Output: 9
Explanation: First day there is only 1 chick.
On second day total number of chicks = 3.
On third day total number of chicks = 9
 

Your Task:
You don't need to read or print anything, Your task is to complete the function NoOfChicks()
which takes N as the input parameter and returns the total no. of chicks on the Nth day.
 

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
 

Constraints:
1 <= N <= 35
*/




class Solution {
public:
	long long dp[40];
	long long int NoOfChicks(int n){
	    dp[1] = 1;
	    for(int i=2;i<=n;i++)
	    {
	        if(i<7)
	        {
	            dp[i] = dp[i-1] + dp[i-1]*2;
	        } 
	        else if(i==7)
	        {
	            long long res = dp[i-1] - dp[i-6] ;
	            dp[i] = res + res*2;
	        }
	        else
	        {
	            long long res = dp[i-1] - (dp[i-6]/3)*2;
	            dp[i] = res + res*2;
	        }
	    }
	    return dp[n];
	}
};
