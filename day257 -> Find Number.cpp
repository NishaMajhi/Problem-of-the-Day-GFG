/*
Given an integer N, You need to find the Nth smallest number which only contains odd digits i.e. 1,3,5,7,9
means no even digits are allowed on that number (12 will not consider).
For example, the starting numbers which only contain odd digits are 1,3,5,7,9,11,13,15,17,19,31,33,35 and so on.



Example 1:
Input:
N=3
Output:
5
Explanation:
First three numbers are 1, 3, 5.
Here 5 is the 3rd number, where contains
only odd digits.


Example 2:
Input:
N=13
Output:
35
Explanation:
First 13 numbers are 1,3,5,7,9,
11,13,15,17,19,31,33,35, here 35 
is the answer.



Your Task:
You don't need to read input or print anything. Your task is to complete the function findNumber() which takes a single variable N 
and returns the smallest Nth number which only contains odd digits.

Expected Time Complexity: O(logN)
Expected Space Complexity: O(1)

Constraints:
1 <= N <= 10^12
*/


class Solution{
public:
    long long findNumber(long long N){
        
        //taking long time then expected
        // int count = 0;
        // int i=1;
        // while(count != N){
        //     int rem = 0;
        //     int flag=0;
        //     while(i){
        //         rem=i%10;
        //         if(rem%2==0)
        //           flag=1;
        //         i=i/10;
        //     }
        //     if(flag==0)
        //       count++;
        //     i+=2;
        // }
        
        // return i;
        
        
        long long curr = 1 , ans = 0;
        int arr[] = {9 , 1 , 3 , 5 , 7 };
        while(N){
            ans = arr[N%5] * curr + ans;
            if(N%5 == 0){
                N = N/5 - 1;
            }else{
                N = N/5;
            }
            curr = curr * 10;
        }
        return ans;
        
    }
};
