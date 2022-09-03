/*
Given a square chessboard, the initial position of Knight and position of a target.
Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
Explanation:

Knight takes 3 step to reach from
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1). 



Example 2:

Input:
N=8
knightPos[ ] = {7, 7}
targetPos[ ] = {1, 5}
Output:
4
Explanation:
Knight takes 4 steps to reach from
(7, 7) to (1, 5):
(4, 5) -> (6, 5) -> (5, 3) -> (7, 2) -> (1, 5).
 

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (KnightPos),
the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and 
returns the minimum number of steps required by the knight to reach from its current position to the given target position.
If it cannot reach the target position return -1.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= N <= 1000
1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N
*/


#include<bits/stdc++.h>
using namespace std;

class Solution { 
public: 
 int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){ 
     int dx[]={+1,+1,+2,+2,-1,-1,-2,-2}; 
     int dy[]={+2,-2,+1,-1,+2,-2,+1,-1}; 
      
     int steps=0; 
     queue<pair<int,int>>q; 
     int p=KnightPos[0]; 
     int f=KnightPos[1]; 
      
     q.push({p,f}); 
     bool visited[N+1][N+1]={false}; 
      
     visited[p][f]=true; 
     while(!q.empty()){ 
         int fl=q.size(); 
         for(int x=0;x<fl;x++){ 
              
             int i=q.front().first; 
             int j=q.front().second; 
              
             q.pop(); 
             if(i==TargetPos[0] and j==TargetPos[1]){ 
                 return steps; 
             } 
              
             for(int f=0;f<8;f++){ 
                 int l=i+dx[f]; 
                 int r=j+dy[f]; 
                  
                 if(l>=1 and l<=N and r>=1 and r<=N and !visited[l][r]){ 
                      
                     visited[l][r]=true; 
                     q.push({l,r}); 
                 } 
             } 
         } 
         steps++; 
     } 
     return steps; 
 } 
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}