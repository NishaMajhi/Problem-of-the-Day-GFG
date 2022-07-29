/*
Geek is the founder of Geek Constructions. He always maintains a black-list of potential employees which can be fired at any moment.

The company has N employees (including Geek), and each employee is assigned a distinct rank (1 <= rank <= N) at the time of joining.
The company has a hierarchical  management such that each employee always has one immediate senior. 

Geek has a strange and unfair way of evaluating an employees performance. He sums the employee's rank and the number of seniors the employee has.
If it is a prime number, the employee is put up on the black-list.

Given an array arr[] in order of the rank of company employees.
For rank i, arr[i] represents the rank of the immediate senior of the employee with the ith rank. 
If geek's rank is i, then arr[i] is always equal to 0 as there is no one senior to him. Find out the number of Black-Listed employees.


Note: The black-list can not contain Geeks name as he is the founder of the company and he is the one that makes the list.


Example 1:

Input:
N = 4
arr[] = {0, 1, 1, 2}

Output: 1

Explanation:
The hierarchy is as follows

       (Geek)
       Rank 1
        /   \
  Rank 2     Rank 3  
      /
Rank 4

Performance = rank + number of seniors
Performance for rank 1 = not considered.
Performance for rank 2 = 2+1 = 3 (prime)
Performance for rank 3 = 3+1 = 4 (not prime)
Performance for rank 4 = 4+2 = 6 (not prime)
Therefore, only employee 1 is black-listed.


Example 2:

Input:
N = 3
arr[] = {2, 3, 0}

Output: 2

Explanation: 
The hierarchy is as follows

       (Geek)
       Rank 3
        /   
  Rank 2     
      /
Rank 1

Performance for rank 3 = not considered. 
Performance for rank 2 = 2+1 = 3 (prime) 
Performance for rank 1 = 1+2 = 3 (prime)
Rank 1 and 2 are both black-listed.

Your Task:  
You don't need to read input or print anything. 
Your task is to complete the function firingEmployees() which takes the array arr[] and its size N as input parameters.
It returns the number of black-listed employees. 


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= i <= N
1 <= arr[i] <= 105
*/

class Solution{   
public:
    int firingEmployees(vector<int> &arr, int n){
        vector<int> adj[n+1];
        int countOfBlackListedEmployees = 0;
        int founder = -1;
        
        map<int,int> mp;
        
        for(int i = 0; i < n; i++) {
            mp[i] = i+1;
            if(arr[i]==0) {
                founder = i;
                continue;
            }
            adj[arr[i]-1].push_back(i);
        }
        
        vector<bool> prime(3*n, true);
        prime[0] = false;
        prime[1] = false;
        
        for(int i = 2; i*i<=3*n; i++) {
            for(int j = 2*i; j<=3*n; j+=i) {
                prime[j] = false;
            }
        }
        
        queue<pair<int,int>> q;
        q.push({founder,0});
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int t = q.front().first;
                int prevSeniorEmployees = q.front().second;
                q.pop();
                
                if(t!=founder) {
                    int judingCriteria = mp[t] + prevSeniorEmployees;
                    
                    if(prime[judingCriteria]) countOfBlackListedEmployees++;
                }
                for(auto it : adj[t]) {
                    q.push({it,prevSeniorEmployees+1});
                }
                
            }
        }
        return countOfBlackListedEmployees;
    }
};
