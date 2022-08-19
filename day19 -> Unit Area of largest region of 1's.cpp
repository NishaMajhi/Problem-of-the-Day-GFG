/*
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 

Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.
Example 2:

Input: grid = {{0,1}}
Output: 1
Explanation: The grid is-
0 1
The largest region of 1's is colored in 
orange.

Your Task:
You don't need to read or print anyhting.
Your task is to complete the function findMaxArea() which takes grid as input parameter and 
returns the area of the largest region of 1's.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 500
*/


#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    int func(int i,int j,vector<vector<int>>&g,vector<vector<int>>&vis){
        
        vis[i][j]=1;
        
        int a=0,b=0,c=0,d=0,e=0,f=0,gt=0,h=0;
        if(i>0 && g[i-1][j] && !vis[i-1][j]){
            a=1+func(i-1,j,g,vis);
        }
        
        if(i<g.size()-1 && g[i+1][j] && !vis[i+1][j]){
            b=1+func(i+1,j,g,vis);
        }
        
        if(j>0 && g[i][j-1] && !vis[i][j-1]){
            c=1+func(i,j-1,g,vis);
        }
        
        if(j<g[0].size()-1 && g[i][j+1] && !vis[i][j+1]){
            d=1+func(i,j+1,g,vis);
        }
        
        if(i>0 && j>0 && g[i-1][j-1] && !vis[i-1][j-1]){
            e=1+func(i-1,j-1,g,vis);
        }
        
        if(i<g.size()-1 && j<g[0].size()-1 && g[i+1][j+1] && !vis[i+1][j+1]){
            f=1+func(i+1,j+1,g,vis);
        }
        
        if(j>0 && i<g.size()-1 && g[i+1][j-1] && !vis[i+1][j-1]){
            gt=1+func(i+1,j-1,g,vis);
        }
        
        if(j<g[0].size()-1 && i>0 && g[i-1][j+1] && !vis[i-1][j+1]){
            h=1+func(i-1,j+1,g,vis);
        }
        
        return a+b+c+d+e+f+gt+h;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n));
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]){
                    ans=max(ans,1+func(i,j,grid,vis));
                }
            }
        }
        
        return ans;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
