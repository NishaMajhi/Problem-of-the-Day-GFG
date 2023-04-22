/*
You are given an array arr of n integers. For each index i, you have to find the sum of all integers present in the array with a value less than arr[i].



Example 1:
Input:
n = 3
arr = {1, 2, 3}
Output:
0 1 3
Explanation:
For 1, there are no elements lesser than itself.
For 2, only 1 is lesser than 2.
And for 3, 1 and 2 are lesser than 3, so the sum is 3.


Example 2:
Input:
n = 2
arr = {4, 4}
Output:
0 0
Explanation:
For 4, there are no elements lesser than itself. 
For 4, there are no elements lesser than itself.
There are no smaller elements than 4.


Your Task:
You don't need to read input or print anything. Your task is to complete the function smallerSum() which takes an integer n and an array arr and
returns an array of length n , the answer for every index.

Expected Time Complexity:O(n log n)
Expected Space Complexity:O(n)

Constraints:
1 <= n <= 105
1 <= arr[i] <= 109
*/



class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
       
       vector<int> copy=arr;
       sort(copy.begin(),copy.end());
       
       vector<long long> sum(n,0);
       sum[0] = copy[0];
       for(int i=1;i<n;i++){
           sum[i]=sum[i-1]+copy[i];
       }
       
       vector<long long> ans(n,0);
       for(int i=0;i<n;i++){
            int index=lower_bound(copy.begin(),copy.end(),arr[i]) - copy.begin();
            if(index==0)
                ans[i]=0;
            else
                ans[i]=sum[index-1];
       }
       
       return ans;
       
    }
};
