/*
You are given two arrays A and B each of length N. You can perform the following operation on array A zero or more times. 

Select any two indices i and j, 1 <= i , j <= N and i != j
Set A[i] = A[i] + 2 and A[j] = A[j]-2
Find the minimum number of operations required to make A and B equal.

Note :

Two arrays are said to be equal if the frequency of each element is equal in both of them.
Arrays may contain duplicate elements.



Example 1:
Input:
N = 3
A[] = {2, 5, 6}
B[] = {1, 2, 10}
Output: 2
Explanation: 
Select i = 3, j = 2, A[3] = 6 + 2 = 8 and A[2] = 5 - 2 = 3
Select i = 3, j = 2, A[3] = 8 + 2 = 10 and A[2] = 3 - 2 = 1
Now A = {2, 1, 10} and B = {1, 2, 10}



Example 2:
Input:
N = 2
A[] = {3, 3}
B[] = {9, 8}
Output: -1
Explanation: 
It can be shown that A cannot be made equal to B.


Your Task: 
You don't need to read input or print anything. Your task is to complete the function solve() which takes the 2 arrays A[], B[] and their size N 
as input parameters and returns the minimum number of moves to make A and B equal if possible else return -1.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105
-109 <= A[i] <= 109
-109 <= B[i] <= 109
*/


class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        
        vector<int> oddA,oddB,evenA,evenB;
        long long sum1=0,sum2=0;
        
        for(int i=0;i<N;i++){
            sum1+=A[i];
            sum2+=B[i];
            if(A[i]%2!=0){
                oddA.push_back(A[i]);
            }
            else{
                evenA.push_back(A[i]);
            }
            if(B[i]%2!=0){
                oddB.push_back(B[i]);
            }
            else{
                evenB.push_back(B[i]);
            }
        }
        
        if(sum1 != sum2 || oddA.size() != oddB.size())
            return -1;
        
        sort(evenA.begin(),evenA.end());
        sort(evenB.begin(),evenB.end());
        sort(oddA.begin(),oddA.end());
        sort(oddB.begin(),oddB.end());
        
        long long ans=0;
        
        for(int i=0; i<oddA.size(); i++)
            ans+=abs(oddA[i] - oddB[i])/2;
            
        for(int i=0; i<evenA.size(); i++)
            ans+=abs(evenA[i] - evenB[i])/2;
            
        return ans/2;
            
    }
};
