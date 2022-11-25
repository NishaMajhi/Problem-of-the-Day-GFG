/*
Shreyansh has an integer N. He is really curious about the binary representation of integers.
He sees that any given integer has a number of set bits. Now he wants to find out that how many positive integers, strictly less than N,
have the same number of set bits as N.
He is a little weak in maths. Help him find the number of integers.
Note : Since N takes large values, brute force won't work.

 

Example 1:

Input:
N = 8
Output: 3
Explanation:
Binary representation of 8 : 1000
So the integers less than 8 with 
same number of set bits are : 4, 2, 1
Hence, the result is 3.  
 

Example 2:

Input:
N = 4
Output: 2
Explanation:
Binary representation of 4 : 100
So the integers less than 4 with 
same number of set bits are : 2, 1
So, The result is 2.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function count() which takes the integer N as input parameters
and returns the required answer.

Expected Time Complexity: O(log(n))
Expected Auxiliary Space: O(log(n)*log(n))
 

Constraints : 
1 <= N <= 10^12
*/



class Solution{
public:
    
    long long dp[100][100];
    
    long long ncr(long long n, long long r)
    {
        if(n < r)   return 0;
        if(r == 0)  return 1;
        if(n == r)  return 1;
        
        if(dp[n][r] != -1)  return dp[n][r];
        
        return dp[n][r] = ncr(n-1, r) + ncr(n-1, r-1);
    }
    
    long long count(long long x) {
        int bit[64];
        for(int i = 0;i<64;i++) bit[i] = 0;
        long long temp = x;
        int i = 0;
        while(temp > 0)
        {
            bit[i] = temp & 1;
            i++;
            temp = temp >> 1;
        }
        long long ans = 0;
        int oc = 0;
        for(int i = 0;i<64;i++)
        {
            if(bit[i] == 1)
            {
                oc++;
                for(int i = 0;i<100;i++)    
                    for(int j = 0;j<100;j++)
                        dp[i][j] = -1;
                ans = ans + ncr(i, oc);
            }
        }
        return ans;
    }
 
};
