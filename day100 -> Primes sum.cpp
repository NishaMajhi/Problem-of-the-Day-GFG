/*
Given a number N. Find if it can be expressed as sum of two prime numbers.


Example 1:
Input: N = 34
Output: "Yes" 
Explanation: 34 can be expressed as 
sum of two prime numbers.



Example 2:
Input: N = 23
Output: "No"
Explanation: 23 cannnot be expressed as
sum of two prime numbers. 

Your Task:  
You dont need to read input or print anything. Complete the function isSumOfTwo() which takes N as input parameter and 
returns "Yes" if can be expressed as sum of two prime numbers. else return "No".

Expected Time Complexity: O(N*sqrt(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
*/



class Solution {
public:
    string isSumOfTwo(int N){
        // code here
        vector<bool> p(N+1,true);
        p[0]=false;
        p[1]=false;
        for(int i=2;i*i<=N;i++){
            if(p[i]==true){
                for(int j=i*i;j<=N;j+=i){
                    p[j]=false;
                }
            }
        }
        
       for(int i=2;i<=N;i++){
           if(p[i]==true){
               int n = N-i;
               if(p[n]==true)
                  return "Yes";
           }
       }
       
       return "No";
    }
};
