/*
There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa to color all the walls on the occasion of New Year.
Alexa can color each wall with one of the K colors.
The cost associated with coloring each wall with a particular color is represented by a 2D costs array of size N * K. 
For example, costs[0][0] is the cost of coloring wall 0 with color 0; costs[1][2] is the cost of coloring wall 1 with color 2, and so on... 
Find the minimum cost to color all the walls such that no two adjacent walls have the same color.

Note: If you are not able to paint all the walls, then you should return -1.



Example 1:
Input:
N = 4, K = 3
costs[][] = {{1, 5, 7},
             {5, 8, 4},
             {3, 2, 9},
             {1, 2, 4}}

Output:
8
Explanation:
Paint wall 0 with color 0. Cost = 1
Paint wall 1 with color 2. Cost = 4
Paint wall 2 with color 1. Cost = 2
Paint wall 3 with color 0. Cost = 1
Total Cost = 1 + 4 + 2 + 1 = 8



Example 2:
Input:
N = 5, K = 1
costs[][] = {{5},
             {4},
             {9},
             {2},
             {1}}
Output:
-1
Explanation:
It is not possible to color all the walls under the given conditions.


Your Task:
Your task is to complete the function minCost() which takes a 2D integer matrix costs as the only argument and returns an integer,
representing the minimum cost to paint all the walls. If you are not able to paint all the walls, then you should return -1

Expected Time Complexity: O(N*K)
Expected Space Complexity: O(N*K)

Constraints:
0 <= N <= 103
0 <= K <= 103
1 <= costs[i][j] <= 105
*/


class Solution{
public:
    int minCost(vector<vector<int>> &c) {
        
        int n = c.size();
        int k = c[0].size();
        
        if(k==1 && n>1)
        return -1;
        
        else if(k==0 || n==0)
        return -1;
        
        int f = INT_MAX,s = INT_MAX;
        for(int i=0;i<k;i++)
        {
            if(c[0][i]<f)
            {
                s = f;
                f = c[0][i];
            }
            else if(c[0][i]<s)
            {
                s = c[0][i];
            }
        }
        
        int f_min,s_min;
        for(int i=1;i<n;i++)
        {
            f_min = INT_MAX,s_min = INT_MAX;
            for(int j=0;j<k;j++)
            {
                if(c[i-1][j]==f)
                c[i][j]+=s;
                else
                c[i][j]+=f;
                
                if(c[i][j]<f_min)
                {
                    s_min = f_min;
                    f_min = c[i][j];
                }
                else if(c[i][j]<s_min)
                {
                    s_min = c[i][j];
                }
            }
            f = f_min;
            s = s_min;
        }
        
        return f;
    }
};
