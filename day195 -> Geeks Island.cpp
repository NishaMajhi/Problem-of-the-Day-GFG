/*
Geeks Island is represented by an N * M matrix mat.
The island is touched by the Indian Ocean from the top and left edges and the Arabian Sea from the right and bottom edges. 
Each element of the matrix represents the height of the cell.

Due to the rainy season, the island receives a lot of rainfall, and the water can flow in four directions(up, down, left, or right)
from one cell to another one with height equal or lower.

You need to find the number of cells from where water can flow to both the Indian Ocean and the Arabian Sea.


Example 1:
Input:
N = 5, M = 5
mat[][] =    {{1, 3, 3, 2, 4},
               {4, 5, 6, 4, 4},
               {2, 4, 5, 3, 1},
               {6, 7, 1, 4, 5},
               {6, 1, 1, 3, 4}}
Output:
8
Explanation:
Indian    ~   ~   ~   ~   ~
Ocean  ~  1   3   3   2  (4) *
        ~  4   5  (6) (4) (4) *
        ~  2   4  (5)  3   1  *
        ~ (6) (7)  1   4   5  *
        ~ (6)  1   1   3   4  *           
           *   *   *   *   * Arabian Sea
Water can flow to both ocean and sea from the cells
denoted by parantheses().For example at index(1,2), the height of that island is 6. If a water drop falls on that island, 
water can flow to up direction(as 3<=6) and reach to Indian Ocean. ALso, water can flow to right direction(as 6>=4>=4) and reach to Arabian Sea.



Example 2:
Input:
N = 2, M = 3
mat[][] =    {{1, 1, 1},
               {1, 1, 1}}
Output:
6 
Explanation:
Water can flow from all cells to both Indian Ocean and Arabian Sea as the height of all islands are same.


Your Task:
Your task is to complete the function water_flow() which takes an integer array mat, integer N and integer M as the input parameter
and returns an integer, denoting the number of cells from which water can to both ocean and sea.

Expected Time Complexity : O(N*M)
Expected Auxiliary Space : O(N*M)

Constraints:

1 <= N, M <= 103
1 <= mat[i][j] <= 106
*/



class Solution{   
public:
   void dfs( int i , int j , vector<vector<int>>&O , vector<vector<int>>&vis , vector<vector<int>>&mat )

    {

        vis[i][j] = 1 ;

        

        int dr[4] = { -1 , 1 , 0 , 0 } ;

        int dc[4] = { 0 , 0 , -1 , 1 } ;

        

        for( int k = 0 ; k < 4 ; k++ )

        {

            int r = i + dr[k] ;

            int c = j + dc[k] ;

            

            if( r < mat.size() && r >= 0 && c < mat[0].size() && c >= 0 )

            {

                if(!vis[r][c] && mat[r][c] >= mat[i][j] )

                {

                    O[r][c] = 1 ;

                    dfs( r , c , O , vis , mat ) ;

                }

            }

        }

    }

    int water_flow(vector<vector<int>> &mat,int N,int M){

    // Write your code here.

    

       vector<vector<int>>A( N , vector<int>(M , 0 )) ;

       vector<vector<int>>I( N , vector<int>(M , 0 )) ;

       vector<vector<int>>vis( N , vector<int>(M , 0 )) ;

       vector<vector<int>>vis1( N , vector<int>(M , 0 )) ;

       

       // starting dfs from indian ocean from top side 

       for( int i = 0 ; i < M ; i++ )

       {

           if(!vis[0][i])

           {

               I[0][i] = 1 ;

               dfs( 0 , i , I , vis , mat ) ;

           }

       }

       

       

       // starting dfs from indian ocean from left side 

       for( int i = 0 ; i < N ; i++ )

       {

           if(!vis[i][0])

           {

               I[i][0] = 1 ;

               dfs( i , 0 , I , vis , mat ) ;

           }

       }

       

       

       

        // starting dfs from Arabian ocean from bottom side 

       for( int i = 0 ; i < M ; i++ )

       {

           if(!vis1[N-1][i])

           {

               A[N-1][i] = 1 ;

               dfs( N-1 , i , A , vis1 , mat ) ;

           }

       }

       

       

       // starting dfs from Arabian ocean from right side  

       for( int i = 0 ; i < N ; i++ )

       {

           if(!vis1[i][M-1])

           {

               A[i][M-1] = 1 ;

               dfs( i , M-1 , A , vis1 , mat ) ;

           }

       }

       

       int count = 0 ;

       

       for( int i = 0 ; i < N ; i++ )

       {

           for( int j = 0 ; j < M ; j++ )

           {

               if( I[i][j] && A[i][j] )

               {

                   count++ ;

               }

           }

       }

       

       return count ;

    }

};
