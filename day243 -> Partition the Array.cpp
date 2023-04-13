/*
Given an array A[] of N integers. The task is to partition the array into four non-empty contiguous subarrays P, Q, R, and S such 
that each element of the array A[] should be present in exactly one subarray.
Let W, X, Y, and Z be the sum of the elements in P, Q, R, and S respectively.
Find the smallest absolute difference between the maximum and the minimum among W, X, Y, and Z.



Example 1:
Input:
N = 5
A[] = [4,2,2,5,1]
Output: 4
Explanation: let partition the array 
P,Q,R,S = [4],[2,2],[5],[1]
W = 4, X = 4, Y = 5, Z = 1 
Differnce = max(W,X,Y,Z)-min(W,X,Y,Z)= 5-1 = 4 



Example 2:
Input:
N = 4
A[] = {4,4,4,4}
Output: 0
Explanation: 
There is only one way to partition 
the array. P,Q,R,S = [4],[4],[4],[4]


Your Task:
You don't need to read input or print anything. The task is to complete the function minDifference() which takes the integer N and 
the array A[] as inputs and returns the smallest absolute difference.

Expected Time Complexity: O(NLogN)
Expected Auxiliary Space: O(N)

Constraints:
4 < N < 105
1 < A[i] < 109
*/


class Solution{
    public:
    
    pair<long long,long long> findMedian(vector<long long> &preSum,int left,int right){
        
        int low=left,high=right-1;
        long long prev=0;
        if(left!=0){
            prev=preSum[left-1];
        }
        long long minVal = 1e10;
        long long t1,t2;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long f=preSum[mid]-prev;
            long long s=preSum[right-1]-preSum[mid];
            if(f>s){
                if( (f-s)<minVal ){
                    minVal=f-s;
                    t1=s;
                    t2=f;
                }
                high=mid-1;
            }
            else if(f==s){
                return {f,s};
            }
            else{
                if( (s-f)<minVal){
                   minVal=s-f;
                    t1=f;
                    t2=s;  
                }
                low=mid+1;
            }
        }
        
        return{t1,t2};
    }
    
    
    long long minDifference(int N, vector<int> &A) {
        
        vector<long long> preSum(N,0);
        for(int i=0;i<N;i++){
            preSum[i]=A[i];
            if(i>0){
                preSum[i]+=preSum[i-1];
            }
        }
        
        long long ans = 1e15;
        for(int i=2;i<=N-2;i++){
            auto p=findMedian(preSum,0,i);
            auto q=findMedian(preSum,i,N);
            long long minVal=min(p.first,q.first);
            long long maxVal=max(p.second,q.second);
            ans = min(ans,(maxVal-minVal));
        }
        
        return ans;
    }
};
