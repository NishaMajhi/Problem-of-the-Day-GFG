/*
Given N nodes of a tree and a list of edges. Find the minimum number of nodes to be selected to light up all the edges of the tree.
An edge lights up when at least one node at the end of the edge is selected.



Example 1:
Input:
N = 6
edges[] = {(1,2), (1,3), (2,4), (3,5), (3,6)}
Output: 2
Explanation: Selecting nodes 2 and 3 lights
up all the edges.



Example 2:
Input:
N = 3
arr[] = {(1,2), (1,3)}
Output: 1
Explanation: Selecting Node 1 
lights up all the edges.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function countVertex() which takes the number of nodes N,
and the list of edges as input parameters and returns the minimum number of nodes selected.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 105
1 ≤ edges ≤ N
Given graph is a valid tree.
*/


class Solution{
    
    int ans;
    public:
    bool isLeaf(int node, int par, vector<int> adj[]){
        
        int cnt = 0;
        for (auto i : adj[node])
            if (i != par)
                cnt++;
                
        return cnt == 0;
    }
    
    bool dfs(int node, int par, vector<int> adj[]){
        
        if(isLeaf(node, par, adj))
            return true;

        bool flag = false;
        for (auto i : adj[node])
            if (i != par)
                flag |= dfs(i, node, adj);

        if(flag)
            ans++;

        return !flag;
    }
    
    int countVertex(int N, vector<vector<int>> edges){
        
        ans = 0;
        vector<int> adj[N + 1];
        for (auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> vis(N + 1);
        dfs(1, -1, adj);
        
        return ans;
    }
};
