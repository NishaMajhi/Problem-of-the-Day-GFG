/*
Given two binary strings A and B consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.


Example 1:

Input:
A = "1101", B = "111"
Output: 10100
Explanation:
 1101
+ 111
10100


Example 2:

Input: 
A = "10", B = "01"
Output: 11
Explanation: 
  10
+ 01
  11

Your Task:
You don't need to read input or print anything. Your task is to complete the function addBinary()
which takes 2 binary string A and B and returns a binary string denoting the addition of both the strings.

Expected Time Complexity: O(max(|A|, |B|)).
Expected Auxiliary Space: O(max(|A|, |B|)) (for output string).

Constraints:
1 ≤ |A|, |B| ≤ 106
*/



class Solution{
public:	
	string addBinary(string A, string B)
	{
	    if(A.length()<B.length()){
	       string temp=A;
	       A=B;
	       B=temp;
	    }
	   int j=A.length()-1;
	   int carry=0;
	   for(int i=B.length()-1;i>=0;i--){
	        if(carry==1){
	            if(A[j]==B[i]){
	                if(A[j]=='1'){
	                    carry=1;
	                }
	                else{
	                    carry=0;
	                }
	                A[j]='1';
	            }
	            else{
	                A[j]='0';
	                carry=1;
	            }
	        }
	        else{
	            if(A[j]==B[i]){
	                if(A[j]=='1'){
	                    carry=1;
	                }
	                else{
	                    carry=0;
	                }
	                A[j]='0';
	            }
	            else{
	                A[j]='1';
	                carry=0;
	            }
	        }
	        j--;
	    }
	    if(carry==1){
	        while(j>=0){
	            if(A[j]=='1'){
	                A[j]='0';
	            }
	            else{
	                A[j]='1';
	                carry=0;
	                break;
	            }
	            j--;
	        }
	        if(carry==1){
	            A='1'+A;
	        }
	    }
	    int i=0;
	    while(i<A.length() && A[i]=='0'){
	        i++;
	    }
	    return A.substr(i);
	}
};
