/*
Given a binary string S consists only of 0s and 1s. The task is to calculate the number of substrings that have more 1s than 0s.


Example 1:
Input:
S = "011"
Output: 4
Explanation: There are 4 substring which 
has more 1s than 0s. i.e "011","1","11" and "1"



Example 2:
Input:
S = "0000"
Output: 0
Explanation: There is no substring
which has more 1s than 0s


Your Task:  
You dont need to read input or print anything. Complete the function countSubstring() which takes the string S as input parameter
and returns the number of substring which has more 1s than 0s.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

Constraints:
1 < |S| < 105
|S| denotes the length of the string S
*/


class Solution{
    public:
    
    void update(vector<int>&bit,int ind){
        
        while(ind<bit.size()){
            bit[ind]+=1;
            ind+=(ind&(-ind));
        }
    }
    
    int get(vector<int>&bit,int ind){
        
        int sum=0;
        while(ind>0){
            sum+=bit[ind];
            ind-=(ind&(-ind));
        }
        return sum;
    }
    
    // 1e5+1 1e5 1e5+1 1e5+2
    long long countSubstring(string a){
        
        vector<int>bit(2e5+2);
        vector<int>z;
        z.push_back(1e5+1);
        for(int i=0;i<a.length();i++){
            if(a[i]=='0')
               z.push_back(z[i]-1);
            else
               z.push_back(z[i]+1);
        }
        long long ans=0;
        for(int i=a.length();i>=0;i--){
            update(bit,z[i]);
            ans+=(a.length()-get(bit,z[i])-i+1);
        }
        
        return ans;
  
        
    }
};
