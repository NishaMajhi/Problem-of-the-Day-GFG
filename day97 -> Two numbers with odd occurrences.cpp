/*
Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers.
Find the two numbers in decreasing order which has odd occurrences.


Example 1:
Input:
N = 8
Arr = {4, 2, 4, 5, 2, 3, 3, 1}
Output: {5, 1} 
Explaination: 5 and 1 have odd occurrences.



Example 2:
Input:
N = 8
Arr = {1 7 5 7 5 4 7 4}
Output: {7, 1}
Explaination: 7 and 1 have odd occurrences.

Your Task:
You don't need to read input or print anything. Your task is to complete the function twoOddNum() which
takes the array Arr[] and its size N as input parameters and returns the two numbers in decreasing order which have odd occurrences.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
2 ≤ N ≤ 106
1 ≤ Arri ≤ 1012
*/


class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N){

        // code here

        vector< long long int> v;
        
        long long int res=0,x=0,count=0,b=0;
        
        for(long long int i=0;i<N;i++){
           res=res^Arr[i];
        }

        while(!(res&(1<<count))){
           ++count;
        }

        b=b|(1<<count);
        for(long long int i=0;i<N;i++){  
           if(Arr[i]&b)
              x=x^res^Arr[i];
        }

        v.push_back(max(x,res^x));
        v.push_back(min(x,res^x));

        return v;
    }
};
