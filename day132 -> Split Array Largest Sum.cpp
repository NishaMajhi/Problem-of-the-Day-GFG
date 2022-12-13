/*
Given an array arr[] of N elements and a number K. Split the given array into K subarrays
such that the maximum subarray sum achievable out of K subarrays formed is minimum possible.
Find that possible subarray sum.


Example 1:

Input:
N = 4, K = 3
arr[] = {1, 2, 3, 4}
Output: 4
Explanation:
Optimal Split is {1, 2}, {3}, {4}.
Maximum sum of all subarrays is 4,
which is minimum possible for 3 splits. 



Example 2:

Input:
N = 3, K = 2
A[] = {1, 1, 2}
Output:
2
Explanation:
Splitting the array as {1,1} and {2} is optimal.
This results in a maximum sum subarray of 2.
 

Your Task:
The task is to complete the function splitArray() which returns the maximum sum subarray after splitting the array into K subarrays
such that maximum sum subarray is minimum possible.


Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ N
1 ≤ arr[i] ≤ 104


Expected Time Complexity: O(N*log(sum(arr))).
Expected Auxiliary Space: O(1).
*/


class Solution {
  public:
    bool possible(int arr[], int mid ,int k, int n){
        
        int parts = 0;
        long long sum = 0;
        
        for(int i = 0; i < n ; i++){
            if( arr[i] > mid )
                return false ;
                
            sum += arr[i] ;
            
            if( sum > mid ){
                sum = arr[i] ;
                parts++;
            } 
            
            else if( sum == mid ){
                sum = 0;
                parts++;
            }
        }
        if( sum != 0  )
        parts++;
        
        if( parts <= k ) 
            return true ;
        
        return false ;
    }
    
    int splitArray(int arr[] ,int n, int k) {
       
        long long int sum = 0;
        
        for(int i = 0; i< n ; i++)
        {
            sum += arr[i] ;
        }
        
        long long int lo = 1 , hi = sum ;
        int ans = INT_MAX ;
        
        while( lo <= hi)
        {
            long long int mid = (lo+hi)/2 ;
            
            if( possible(arr,mid,k,n))
            {
                ans = mid ; 
                hi = mid-1 ;
            } 
            else 
            {
                lo = mid+1 ;
            }
        }
        return ans ;
        
    }
};
