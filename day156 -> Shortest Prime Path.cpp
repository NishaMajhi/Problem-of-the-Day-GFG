/*
You are given two four digit prime numbers Num1 and Num2. 
Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only one single digit at a time.
Every number obtained after changing a digit should be a four digit prime number with no leading zeros.


Example 1:
Input:
Num1 = 1033 
Num2 = 8179
Output: 6
Explanation:
1033 -> 1733 -> 3733 -> 3739 -> 3779
                 -> 8779 -> 8179.
There are only 6 steps required to reach
Num2 from Num1, and all the intermediate
numbers are 4 digit prime numbers.



Example 2:
Input:
Num1 = 1033 
Num2 = 1033
Output:
0

Your Task:  
You don't need to read input or print anything. Your task is to Complete the constructor of the class Solution to precompute a list of prime numbers.  
Complete function shortestPath() which takes two integers Num1 and Num2 as input parameters and 
returns the distance of the shortest path from Num1 to Num2. If it is unreachable then return -1.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)


Constraints:
1000 ≤ Num1,Num2 ≤ 9999
Num1 and Num2 are prime numbers.
*/


class Solution{   
  public:
  
    bool isPrime(int num){

        if(num==1)
           return false;

        for(int i=2;i*i<=num;i++){
            if(num%i==0) 
               return false;
               
        }

        return true;

    }
  
    int shortestPath(int num1,int num2){   

        if(!isPrime(num1) and !isPrime(num2)) 
           return 0;

        string s = to_string(num1);
        string e = to_string(num2);
        unordered_set<string> st;
        queue<pair<string,int>> q;
        q.push({s,0});
        st.insert(s);

        while(!q.empty()){
            string num = q.front().first;
            int steps = q. front().second;
            q.pop();
            if(num == e)
               return steps;
            for(int i=0;i<4;i++){
                char original = num[i];
                for(char ch = 0 ; ch <= 9 ; ch++){
                    if(ch==0 and i==0)
                       continue;
                    num[i] = char(ch +'0');
                    int val = stoi(num);
                    if(isPrime(val)){
                        if(st.find(num)==st.end()){
                            st.insert(num);
                            q.push({num,steps+1});
                        }
                    }
                }
                num[i] = original;
            }
        }

        return -1;

    }

};
