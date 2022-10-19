/*
A Hamiltonian path, is a path in an undirected graph that visits each vertex exactly once.
Given an undirected graph, the task is to check if a Hamiltonian path is present in it or not.


Example 1:
Input:
N = 4, M = 4
Edges[][]= { {1,2}, {2,3}, {3,4}, {2,4} }
Output:
1 
Explanation: 
There is a hamiltonian path: 
1 -> 2 -> 3 -> 4 



Example 2:
Input:
N = 4, M = 3 
Edges[][] = { {1,2}, {2,3}, {2,4} } 
Output: 
0 
Explanation: 
It can be proved that there is no 
hamiltonian path in the given graph

Your task:
You don't need to read input or print anything. Your task is to complete the function check() 
which takes the N (the number of vertices), M (Number of edges) and 
the list of Edges[][] (where Edges[i] denotes the undirected Edge between vertices Edge[i][0] and Edges[i][1] ) as input parameter 
and returns true (boolean value) if the graph contains Hamiltonian path,otherwise returns false. 


Expected Time Complexity: O(N!).
Expected Auxiliary Space: O(N+M).


Constraints:
1 ≤ N ≤ 10
1 ≤ M ≤ 15
Size of Edges[i] is 2
1 ≤ Edges[i][0],Edges[i][1] ≤ N
*/


class Solution
{ 
public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        map<int,vector<int>> mp;
        for(int i = 0;i<Edges.size();i++){
            //storing nodes in adjacency list form
            int u = Edges[i][0];
            int v = Edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<bool> vis(mp.size()+1,false); //visited array for checking visited nodes
        
        for(int i = 1;i<=mp.size();i++){ //loop for every node in the graph
            int count = 1; //number of visited nodes
            if(dfs(i,mp,vis,count))
                return true;
        }
        return false;
    }
    bool dfs(int i,map<int,vector<int>> &mp,vector<bool> &vis, int count){
        if(count==mp.size()) //traverse every node of the path
            return true;
        vis[i] = true; //marking node as visited
        for(auto &it: mp[i]){ //going for unvisited adjacent nodes
            if(vis[it]==false){
                if(dfs(it,mp,vis,count+1))
                    return true;
            }
        }
        vis[i] = false; //marking node as unvisited
        return false; 
    }
};
