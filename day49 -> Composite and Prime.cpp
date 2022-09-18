/*
Given two integers L and R find the difference of number of composites and primes between the range L and R (both inclusive).

Example 1:

Input: L = 4, R = 6
Output: 1
Explanation: Composite no. are 4 and 6.
And prime is 5.



Example 2:

Input: L = 4, R = 4
Output: 1
Explanation: There is no prime no. in [L,R]
 

Your Task:
You don't need to read or print anything. 
Your task is to complete the function Count() which takes L and R as input parameter and 
returns difference between no. of composites and primes between [L,R].
 

Expected Time Complexity: O(nlog(n)) where n = R - L + 1
Expected Space Complexity: O(n)
 

Constraints:
1 <= L <= R <= 105 
*/


class Solution {
	public:
		int Count(int L, int R){
		    
		    vector<int> prime(R+1,1);
		    for(int i=2; i*i<=R; i++){
		        if(prime[i] == 1){
		            for(int j=i*i; j<=R; j+=i){
		                prime[j] = 0;
		            }
		        }
		    }
		    
		    int countComp = 0,countPrime = 0;
		    
		    for(int i=max(2,L); i<=R; i++){
		        
		        if(prime[i] == 1)
		           countPrime++;
		        else
		           countComp++;
		    }
		    
		    return countComp-countPrime;
		}

};
