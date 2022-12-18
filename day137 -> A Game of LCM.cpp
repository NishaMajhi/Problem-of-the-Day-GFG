/*
Given an integer N. Find maximum LCM (Least Common Multiple) that can be obtained from four numbers less than or equal to N.
Note: Duplicate numbers can be used.

Example 1:
Input:
N = 4
Output: 12
Explanation:
The four numbers can be [4,4,3,2] or
[4,4,4,3], etc. It can be shown that 12 is
the maximum LCM of four numbers that can
be obtained from numbers less than or equal 
to 4.



Example 2:
Input:
N = 5
Output: 60
Explanation:
The four numbers can be [5,5,4,3] or
[5,4,3,2], etc. 60 is the maximum that can
be obtained.


Your Task:
You don't need to read input or print anything. Your task is to complete the function maxGcd() which takes N as the input parameter
and returns the maximum LCM that can be obtained from four numbers less than or equal to N.

Expected Time Complexity: O( Log2(max(N)) )
Expected Auxillary Space: O(1)

Constraints:
2 ≤ N ≤ 104
*/


class Solution {
  public:
    // check if gcd of a,b are coprime or not, 1-coprime, 0-Not_comprime

    long long gc(long long a, long long b){

        if(b==0) {
            if(a==1)
               return 1;
            else
               return 0;
        }

        return gc(b, a%b);

    }

  

    long long maxGcd(int N) {

        if(N<=2)
           return N;

        if(N==3) 
           return 6;

        // ans = num * (three numbers which are coprime with the current product)

        int count = 1; // total numbers can be max of 4

        long long lcm = N;

        for(int i = N-1; i>=1 && count<4; i--){
            if(gc(lcm, i)==1){
                lcm *= i;
                count++;
            }
        }
        return lcm;
    }

};
