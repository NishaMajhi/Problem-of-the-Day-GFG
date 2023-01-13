/*
You are given an array arr[ ] of integers having N elements and a non-weighted undirected graph having N nodes and M edges. 
The details of each edge in the graph is given to you in the form of list of list. 
Your task is to find the number of lucky permutations of the given array. 

An array permutation is said to be lucky if for every node Vi  [1 <= i <= N-1] in the array
there exists an edge between the nodes Vi and Vi+1 in the given graph.



Example 1:
Input:
N = 3, M = 2
arr = {1, 2, 3}
graph = {{3, 1}, {1, 2}}
Output:
2
Explanation:
All possible permutations of the 
array are as follows-
{1,2,3}: There is an edge between 1 and 
2 in the graph but not betwen 2 and 3.

{2,1,3}: There is an edge between (2,1)
and (1,3) in the graph.

{3,1,2}: There is an edge between (3,1)
and (1,2) in the graph.

Out of the 3 possible permutations, 
2 are lucky. Therefore, answer is 2.



Example 2:
Input:
N = 2, M = 1
arr = {1, 1}
graph = {{1, 2}}
Output :
0
Explanation:
There is no lucky permutation in the 
given graph. 


Your Task:  
You don't need to read input or print anything. Your task is to complete the function luckyPermutations() which takes the two integers N and M,
an array arr[ ] and a list of lists named graph of size M as input parameters and returns the count of lucky permutations.


Expected Time Complexity: O(N2*2N)
Expected Auxiliary Space: O(N*2N)


Constraints:
2 ≤ N ≤ 15
1 ≤ M ≤ (N*(N-1))/2
1 ≤  arr[i], graph[i][j] ≤ N 
There are no self-loops and repeated edges in the graph.
*/



class Solution {
  public:
    long long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        
        // Creating adjacency matrix, adj
        // Initializing adj
        // setting adj as true for all edges
        bool adj[N][N];
        memset(adj,0,sizeof adj);
        for(auto edge:graph) 
        adj[edge[0]-1][edge[1]-1]=adj[edge[1]-1][edge[0]-1]=1;
        
        
        // creating and initializing dp
        long long dp[N][(1<<N)];
        memset(dp,0,sizeof dp);
        for(int i=0; i<N; i++) dp[i][(1<<i)] = 1;
        
        
        
        for(int subset=0; subset<(1<<N); subset++)// check for all 2^N subsets
        {
            for(int curr=0; curr<N; curr++) // going through all the nodes
            {
                if(!(subset&(1<<curr))) continue; // skip if current node is not part of subset

                    for(int prev=0; prev<N; prev++) // going through all previous nodes
                    {
                        if(curr==prev || arr[curr]==arr[prev])  // skip if previous node is same as current node
                            continue;
                        if(!(subset&(1<<prev)))  // skip if previous node is not in subset
                            continue;
                        if(!adj[arr[prev]-1][arr[curr]-1])  // skip if no edge between current and previous node
                            continue;
                        dp[curr][subset] += dp[prev][subset^(1<<curr)]; // add all possible ways to end at current node with the given subset.
                        
                    }
            }
        }
        
        // Answer is all possible ways where every node is visited(i.e. subset with all 1's) 
        long long ans = 0;
        for(int i=0; i<N; i++){
            ans+= dp[i][(1<<N)-1];
        }
        
        return ans;
        
        
    }
};
