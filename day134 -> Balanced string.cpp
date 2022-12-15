/*
Given an integer N.Create a string using only lowercase characters from a to z that follows the given rules.

When N is even:

Use N/2 characters from the beginning of a-z and N/2 characters from the ending of a-z.

When N is greater than 26,continue repeating the instructions until length of string becomes N.

When N is odd:

Case 1: If the sum of digits of N is even, Select (N+1)/2 characters from the beginning of a-z and (N-1)/2 characters from the ending of a-z.

Case 2: If the sum of digits of N is odd, Select (N-1)/2 characters from the beginning of a-z and (N+1)/2 characters from the ending of a-z.

When N is greater than 26,continue repeating the instructions until length of string becomes N.

 

Example 1:
Input: 
N=21
Output: 
abcdefghijpqrstuvwxyz
Explanation:
Since 21 is odd and sum of digits
of 21 is also odd,we take (21-1)/2=10 
characters from the beginning and 
(21+1)/2=11 characters from the 
end of a-z.



Example 2:
Input:
N=28 
Output: 
abcdefghijklmnopqrstuvwxyzaz
Explanation: 
Since 28>26, we keep repeating 
the process until length of string becomes 
28.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function BalancedString() which takes the integer N as input parameter
and returns the string created using given procedures.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
 

Constraints:
1 <= N <= 105
*/


class Solution {
  public:  
    string HalfAns(int s,int e){
        string ans;
        for(int i=0;i<s;i++){
            ans.push_back(char(97+i));
        }
        for(int i=e;i>0;i--){
            ans.push_back(char(122-i+1));
        }
        return ans;
    }

    string BalancedString(int N) {
        string result;
        if(N<=26 && N%2==0){
            result=HalfAns(N/2,N/2);
        }
        if(N>26 && N%2==0){
            string result1="";
            while(N-26 >=0){
                // string result1="";
                result1=result1.append(HalfAns(13,13));
                N=N-26;
                if(N<26){
                    string result2=HalfAns(N/2,N/2);
                    result=result1.append(result2);
                }
            }
        }
        if(N<=26 && N%2!=0){
            int temp=N;
            int m,sum=0;
            while(temp>0){
                m=temp%10;
                sum=sum+m;
                temp=temp/10;
            }
            // cout<<sum<<endl;
            if(sum%2 == 0){
                result=HalfAns((N+1)/2,(N-1)/2);
            }
            if(sum%2 !=0){
                result=HalfAns((N-1)/2,(N+1)/2);
            }
        }
        if(N>26 && N%2 !=0){
            int temp=N;
            int m,sum=0;
            while(temp>0){
                m=temp%10;
                sum=sum+m;
                temp=temp/10;
            }
            string result1="";
            while(N-26 >=0){
                // string result1="";
                result1=result1.append(HalfAns(13,13));
                N=N-26;
                if(N<26){
                    if(sum%2 == 0){
                        string result2=HalfAns((N+1)/2,(N-1)/2);
                        result=result1.append(result2);
                    }
                    if(sum%2 !=0){
                        string result2=HalfAns((N-1)/2,(N+1)/2);
                        result=result1.append(result2);
                    }
                    
                }
            }
        }
        return result;
    }
};
