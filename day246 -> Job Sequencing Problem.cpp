/*
Given a set of N jobs where each jobi has a deadline and profit associated with it. 
Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.



Example 1:
Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).



Example 2:
Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).


Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N a
nd an array of Jobs(Job id, Deadline, Profit) as input and returns an array ans[ ] in which ans[0] contains the count of jobs and ans[1] contains maximum profit.

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)

Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500
*/



/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
    bool static comp(Job a,Job b){
        if(a.profit==b.profit)
           return a.dead<b.dead;
        return a.profit>b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        
        vector<bool> vis(n,false);
        int totalProf=0,count=0;
        
        for(int i=0;i<n;i++){
            int dead=arr[i].dead;
            int prof = arr[i].profit;
            for(int j=dead-1;j>=0;j--){
                if(vis[j]==false){
                    vis[j]=true;
                    count++;
                    totalProf += prof;
                    break;
                }
            }
        }
        
        return {count,totalProf};
    } 
};
