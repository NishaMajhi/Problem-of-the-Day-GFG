/*
Find the count of numbers less than equal to N having exactly 9 divisors.
 

Example 1:

Input:
N = 100
Output:
2
Explanation:
The two numbers which have 
exactly 9 divisors are 36 and 100.


Example 2:

Input:
N = 1000
Output:
8 
Explanation:
The numbers are:
36 100 196 225 256 441 484 676

Your Task:  
You don't need to read input or print anything.
Your task is to complete the function nineDivisors() which takes an integer N as an input parameter and
returns the total number of elements from 1 to N inclusive, that have exactly 9 divisors.

Expected Time Complexity: O(sqrt(N))
Expected Auxiliary Space:  O(sqrt(N))
 

Constraints:
1<=N<=1010

 
*/

class Solution{   
public:
    long long int nineDivisors(long long int N){
        //Code Here
        if(N < 36) return 0;
        
        long long size = sqrt(N);
        
        long long count = 0;
        
        vector<long long> sieve(size+1);
        
        for(int i = 1; i <= size; i++)
        {
            sieve[i] = i;
        }
        
        for(long long i = 2; i*i <= size; i++)
        {
            if(sieve[i] != i) continue;
            for(long long j = i*i; j <= size; j+=i)
            {
                if(sieve[j] == j)
                sieve[j] = i;
            }
        }
        
        for(long long i = 2; i <= size; i++)
        {
            long long p = sieve[i];
            
            long long q = sieve[i/p];
            
            if((p!=q && p*q == i && q !=1) || (sieve[i] == i && pow(i,8) <= N))
            {
                count++;
            }
        }
        return count;
    }
};
