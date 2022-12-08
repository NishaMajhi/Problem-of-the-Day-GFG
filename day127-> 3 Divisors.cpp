/*
You are given a list of q queries and for every query, you are given an integer N.  
The task is to find how many numbers(less than or equal to N) have number of divisors exactly equal to 3.


Example 1:
Input:
q = 1
query[0] = 6
Output:
1
Explanation:
There is only one number 4 which has
exactly three divisors 1, 2 and 4 and
less than equal to 6.



Example 2:
Input:
q = 2
query[0] = 6
query[1] = 10
Output:
1
2
Explanation:
For query 1 it is covered in the
example 1.
query 2: There are two numbers 4 and 9
having exactly 3 divisors and less than
equal to 10.


Your Task:  
You don't need to read input or print anything. Your task is to complete the function threeDivisors()
which takes an integer q and a list of integer of size q as input parameter and 
returns the list containing the count of the numbers having exactly 3 divisors for each query.

Expected Time Complexity: O(q*N*log(log(N)))
Expected Auxiliary Space: O(N), where N is min(10^6,N)

Constraints : 
1 <= q <= 10^3
1 <= query[i] <= 10^12
*/


class Solution
{
public:

     vector<bool> seiveOfErathosesis(int n){

        vector<bool>arr(n+1,true);
        arr[0] = arr[1] = false;
        
        for(int i=2;i*i<=n;i++){
            if(arr[i] == true){
                for(int j = i*i;j<=n;j+=i){
                   arr[j] = false;
                }
            }
        }
        return arr;

    }
    
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // If any number have just exactly 3 divisor means it is a sqaure of any prime number.
        // Means sqaure of any prime number have exactly 3 divisor  which is 2 of prime number
        // and the 3 one will be  that squared number
        
        vector<bool>prime;
        vector<int>divVec;

        int c;
        prime = seiveOfErathosesis(1000000);

        for(int i=0;i<query.size();i++){
            c=0;
            long long int x = query[i];
            for(long long j = 2;j*j<=x;j++){
                 if(prime[j] == true)
                         c++;
             }
             divVec.push_back(c);
        }

        return divVec;
    }
};
