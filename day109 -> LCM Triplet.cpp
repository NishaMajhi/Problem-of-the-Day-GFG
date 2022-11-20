/*
Given a number N.Find the maximum possible LCM that can be attained by any three numbers less than or equal to N.
Note- LCM stands for Lowest Common Multiple. Also, Numbers can be repeated.


Example 1:
Input:
N=9
Output:
504
Explanation:
504 is the maximum LCM that can be attained
by any triplet of numbers less than or equal 9.
The triplet which has this LCM is {7,8,9}.



Example 2:
Input:
N=7
Output:
210
Explanation:
210 is the maximum LCM that can be attained
by any triplet of numbers less than or equal 7.
The triplet which has this LCM is {5,6,7}.

Your Task:
You don't need to read input or print anything. Your task is to complete the function lcmTriplets() that takes a number N as input parameter
and returns the maximum LCM that can be attained by any three numbers less than or equal to N.


Expected Time Complexity:O(logN)
Expected Auxillary Space:O(logN)


Constraints:
1<=N<=106 
*/



class Solution {
  public:
    bool isCoprime(int x1, int x2) {
        //TC = O(log(max(x1, x2)))
        if(__gcd(x1, x2) == 1) return true;
        else return false;
    }

    long long lcmTriplets(long long n) {
        //case1 when n is less than 3
        if(n == 1) return 1;
        if(n == 2) return 2;
        //case 2 when n is odd ans = n*n-1*n-2;
        if(n%2 == 1) {
            long long ans = n*(n-1)*1LL;
            return ans*(n-2);
        }

        //case 3 when n is even but not divisible by 3
        if(n%2 == 0 && n%3 != 0) {
            long long ans = n*(n-1)*1LL;
            return ans*(n-3);
        }
        //case 4 if n is even and also div by 3
        //eg n = 6
        int x1 = n, x2 = n-1, x3 = n-2;
        while(min(x1, min(x2, x3)) > 0) {
            int mn = min(x1, min(x2, x3));
            int mx = max(x1, max(x2, x3));
            if(mx-mn <= 3) {
                if(isCoprime(x1, x2) && isCoprime(x2, x3) && isCoprime(x3, x1)) {
                    long ans = x1*x2*1LL;
                    return ans*x3; 
                }
                x3 = x3-1;
            } else {
                x3 = x3+1;
                x2 = x2-1;
                x1 = x1-1;
                long ans = x1*x2*1LL;
                return ans*x3; 
            }
        } 
        return -1;
    }

};
