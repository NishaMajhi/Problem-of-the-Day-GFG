/*
Given a positive integer n, generate all possible unique ways to represent n as sum of positive integers.

Note: The generated output is printed without partitions. Each partition must be in decreasing order. Printing of all the partitions is done in reverse sorted order. 

Example 1:

Input: n = 3
Output: 3 2 1 1 1 1
Explanation: For n = 3, 
{3}, {2, 1} and {1, 1, 1}.
 

Example 2:

Input: n = 4 
Output: 4 3 1 2 2 2 1 1 1 1 1 1
Explanation: For n = 4, 
{4}, {3, 1}, {2, 2}, {2, 1, 1}, {1, 1, 1, 1}.

Your Task:
You don't need to read or print anything. Your task is to complete the function UniquePartitions() which takes n as input parameter and returns a list of all possible combinations in lexicographically decreasing order. 
 

Expected Time Complexity: O(2^n)
Expected Space Complexity: O(n)

 

Constraints:
1 <= n <= 25
*/

public:
	    vector<vector<int>> ans;
        void fun(int n,int x,vector<int> &v){
            if(n == 0){
               ans.push_back(v);
              return;
            }

        for(int i=x;i>0;i--){

            if(n-i>=0){

                v.push_back(i);

                fun(n-i,i,v);

                v.pop_back();

            }

        }

    }

    

    vector<vector<int>> UniquePartitions(int n) {

        vector<int>v;

        fun(n,n,v);

        return ans;

    }
