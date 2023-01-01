/*
Given a number n, find count of all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits.
The anwer can be very large. So, you have to return answer modulo 109+7.


Example:
Input: n = 2
Output: 6
Explanation: There are 6 sequences of length 
2*n, the sequences are 0101, 0110, 1010, 1001, 
0000 and 1111.


Example:
Input: n = 1
Output: 2
Explanation: There are 2 sequence of length 
2*n, the sequence are 00 and 11.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function compute_value() which takes n as input parameter
and returns count of all binary sequence of length 2*n such that sum of first n bits is same as sum of last n bits modulo 109 + 7.
 

Expected Time Complexity: O(n * log(n))
Expected Space Complexity:  O(1)
 

Constraints:
1 <= n <= 105
*/


class Solution{
    public:
    
    int inv(int n, int m, int mod=1000000007){
      
        if(m==0)
           return 1;
        if(m&1) 
           return (n*1ll*inv(n, m-1))%mod;
        
        int tmp=inv(n, m/2);
        
        return (tmp*1ll*tmp)%mod;
    }

    int compute_value(int n){
        
        int m = 1000000007;
        long long fact2N=1, factN;
        for(int i=1; i<=2*n; i++){
            fact2N *= i;
            fact2N %= m;
            if(i==n)
                factN=fact2N;
        }

        factN = (factN*factN)%m;
        return (fact2N * 1ll * inv(factN, m-2))%m;

    }

};
