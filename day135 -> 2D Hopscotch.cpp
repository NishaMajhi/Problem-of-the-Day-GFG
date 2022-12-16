/*
Aakriti, Avantika and Mehak are playing 2D Hopscotch. The arena is in the form of a n*m 2D matrix. 
But the position of the cells is slightly modified as shown below. 


Mehak starts the game from tile (i,j) while Avantika and Aakriti direct her.
In each turn Mehak will collect all the stones present (1 or 2) steps away from where she is standing.
Avantika can direct Mehak to take 1 step and and Aakriti can direct Mehak to take 2 steps. 
If the director ty is known to you as ty = 0 being Avantika and 1 being Aakriti, find the number of stones that Mehak will collect. 


Example 1:
Input: 
n = 3, m = 3
mat = {{5, 9, 7}, 
       {6, 4, 5}, 
       {8, 1, 2}}
ty = 0, 
i = 1, j = 1
Output: 31
Explaination: 
ty=0, so Avantika is the director. 
ie- Mehak will move only one step in 
any direction to collect the stones.
(0,1), (1,0), (1,2), (2,1), (2,2), (2,0) 
are at a distance of 1 from (1,1). 
Adding them 9+6+5+8+1+2=31.


Example 2:
Input: 
n = 3, m = 3
mat = {{5, 9, 7}, 
       {6, 4, 5}, 
       {8, 1, 2}}
ty = 1, 
i = 1, j = 1
Output: 12
Explaination: 
ty=1, so Aakriti is the director. 
ie- Mehak can move 2 steps. 
(0,0) and (0,2) are the only tiles that 
are at a distance of two from (1,1). 
Adding them gives 5+7=12.

Your Task:
You do not need to read input or print anything. Your task is to complete the function hopscotch() which takes n, m, mat, ty, i and j as input parameters
and returns the number of collected stones.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n, m ≤ 1000000
0 ≤ i < n
0 ≤ j < m 
*/


class Solution{
    private :
    int fun(int n,int m,vector<vector<int>> grid,int delrow[],
            int delcol[],int i,int j,int size){

        int ans = 0;
        for(int k = 0;k<size;k++){
            int nrow = delrow[k] + i;
            int ncol = delcol[k] + j;
            if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m){
                ans = ans + grid[nrow][ncol];
            }
        }

        return ans;

    }

    public:
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j){

       int dx1o[] = {-1,0,1,1,1,0};
        int dy1o[] = {0,1,1,0,-1,-1};
        int dx1e[] = {-1,-1,0,1,0,-1};
        int dy1e[] = {0,1,1,0,-1,-1};

        int dx2o[] = {-1,-1,-2,-1,-1,0,0,1,1,2,2,2};
        int dy2o[] = {-2,-1,0,1,2,-2,2,-2,2,-1,0,1};
        int dx2e[] = {-2,-2,-2,-1,-1,0,0,1,1,1,1,2};
        int dy2e[] = {-1,0,1,-2,2,-2,2,-2,-1,1,2,0};

        int ans = 0;
        if(ty == 0){
            if(j%2 == 0){
                ans = fun(n,m,mat,dx1e,dy1e,i,j,6);
            }
            else{
                ans = fun(n,m,mat,dx1o,dy1o,i,j,6);
            }
        }
        else{
            if(j%2 == 0){
                ans = fun(n,m,mat,dx2e,dy2e,i,j,12);
            }
            else{
                ans = fun(n,m,mat,dx2o,dy2o,i,j,12);
            }

        }

        return ans;

    }

};
