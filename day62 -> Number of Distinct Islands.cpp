/*
Given a boolean 2D matrix grid of size n * m. 
You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island.
Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).


Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.



Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.



Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands()
which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
*/



class Solution {
  public:

    string dfs(vector<vector<int>>& grid,vector<vector<bool>>&visited,int r,int c,string direction){

       if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() 
              || visited[r][c]==true || grid[r][c]==0){
            return "0";
       }

       visited[r][c]=true;

       return direction+dfs(grid,visited,r-1,c,"U") +
              dfs(grid,visited,r+1,c,"D") +
              dfs(grid,visited,r,c-1,"B") +
              dfs(grid,visited,r,c+1,"F");

    }

    int countDistinctIslands(vector<vector<int>>& grid) {

        if(grid.size()==0){
            return 0;
        }

        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        set<string>unique;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                    string str=dfs(grid,visited,i,j,"X");
                    unique.insert(str);
                }
            }
        }


        return unique.size();

    }

};
