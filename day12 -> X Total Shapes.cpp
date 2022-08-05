/*
Given  a grid of n*m consisting of O's and X's. The task is to find the number of 'X' total shapes.
Note: 'X' shape consists of one or more adjacent X's (diagonals not included).
 

Example 1:
Input: grid = {{X,O,X},{O,X,O},{X,X,X}}
Output: 3

Explanation: 
The grid is-
X O X
O X O
X X X
So, X with same colour are adjacent to each 
other vertically for horizontally (diagonals 
not included). So, there are 3 different groups 
in the given grid.



Example 2:

Input: grid = {{X,X},{X,X}}
Output: 1

Expanation: 
The grid is- 
X X
X X
So, X with same colour are adjacent to each
other vertically for horizontally (diagonals
not included). So, there is only 1 group
in the given grid.
 

Your Task:
You don't need to read or print anything.
Your task is to complete the function xShape() which takes grid as input parameter and returns the count of total X shapes.
 

Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 100
*/


#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    bool isSafe(int i,int j,int n,int m){
        if(i>=0 and i<n and j>=0 and j<m)
           return true;
        else 
           return false;
    }
    
    bool isValid(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& vis){
        if(vis[i][j]==0 and grid[i][j]=='X') return true;
        else return false;
    }
    
    void solve(vector<vector<char>>& grid,int i,int j,int n,int m,vector<vector<int>>& vis){
        grid[i][j]='0';
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            if( isSafe(i+dx[k],j+dy[k],n,m) and isValid(grid,i+dx[k],j+dy[k],vis) )
                solve(grid,i+dx[k],j+dy[k],n,m,vis);
        }
        
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        int cnt=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    solve(grid,i,j,n,m,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
