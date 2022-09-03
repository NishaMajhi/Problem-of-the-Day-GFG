/*
Geek is organizing a party at his house. For the party, he needs exactly N donuts for the guests.
Geek decides to order the donuts from a nearby restaurant, which has L chefs and each chef has a rank R. 
A chef with rank R can make 1 donut in the first R minutes, 1 more donut in the next 2R minutes, 1 more donut in 3R minutes, and so on.
For example. a chef with rank 2, can make one donut in 2 minutes, one more donut in the next 4 minutes, and one more in the next 6 minutes.
So, it take 2 + 4 + 6 = 12 minutes to make 3 donuts. A chef can move on to making the next donut only after completing the previous one.
All the chefs can work simultaneously.
Since, it's time for the party, Geek wants to know the minimum time required in completing N donuts. Return an integer denoting the minimum time

Example 1:

Input:
N = 10
L = 4
rank[] = {1, 2, 3, 4}
Output: 12
Explanation: 
Chef with rank 1, can make 4 donuts in time 1 + 2 + 3 + 4 = 10 mins
Chef with rank 2, can make 3 donuts in time 2 + 4 + 6 = 12 mins
Chef with rank 3, can make 2 donuts in time 3 + 6 = 9 mins
Chef with rank 4, can make 1 donuts in time = 4 minutes
Total donuts = 4 + 3 + 2 + 1 = 10 and total time = 12 minutes.


Example 2:

Input:
N = 8
L = 8
rank[] = {1, 1, 1, 1, 1, 1, 1, 1}
Output: 1
Explanation: 
As all chefs are ranked 1, so each chef can make 1 donuts 1 min.
Total donuts = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 8 and total time = 8 minutes. 

 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findMinTime()
which takes an integer N as input and an array A[] of length L denoting the ranks and return an integer denoting the minimum time.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 103
1 <= L <= 50
1 <= L[i] <= 8
*/


class Solution{
    int time(int rank,int n){
        int i=1,t=0,res=0;
        while(t<n){
            res+=i*rank;t++;i++;
        }
        return res;
    }
    int donuts(int time,int rank){
        int t=0,d=0,i=1;
        while(t<time){
            d++;
            t+=i*rank;i++;
        }
        if(t>time)d--;
        return d;
    }
    public:
    int findMinTime(int N, vector<int>&A, int L){
        //write your code here
        int high = time(*max_element(A.begin(),A.end()),N);
        int low = 1;
        int res = 0;
        while(low<=high){
            int mid = (low+high)/2;
            int dons = 0;
            for(int i=0;i<L;i++){
                dons+=donuts(mid,A[i]);
            }
            if(dons>=N){
                res = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};
