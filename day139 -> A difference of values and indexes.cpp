/*
Given an unsorted array arr[ ] of size n, you need to find the maximum difference of absolute values of elements and indexes,
i.e., for i <= j, calculate maximum of | arr[ i ] - arr[ j ] | + | i - j |. 



Example 1:

Input : 
n = 3
arr[ ] = {1, 3, -1}
Output: 5
Explanation:
Maximum difference comes from indexes 
1, 2 i.e | 3 - (-1) | + | 1 - 2 | = 5



Example 2:

Input : 
n = 4
arr[ ] = {5, 9, 2, 6} 
Output:  8
Explanation: 
Maximum difference comes from indexes 
1, 2 i.e | 9 - 2 | + | 1 - 2 | = 8
 

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function maxDistance() 
that takes an array (arr), sizeOfArray (n), and return the maximum difference as given in the question. 
The driver code takes care of the printing.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).
 

Constraints:
1 <= n <= 5*(10^5)
-10^6 <= arr[ i ] <= 10^6
*/


class Solution{
  public:
    int maxDistance(int arr[], int n){
        
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            max1 = max(max1, arr[i] - i);
            min1 = min(min1, arr[i] - i);
            max2 = max(max2, arr[i] + i);
            min2 = min(min2, arr[i] + i);
        }
        int maxDiff = max(max1 - min1, max2 - min2);
        return  maxDiff  ;
    
    } 
};
