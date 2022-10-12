/*
Given a string w, integer array b,  character array x and an integer n. n is the size of array b and array x. 
Find a substring which has the sum of the ASCII values of its every character, as maximum.
ASCII values of some characters are redefined.

Note: Uppercase & lowercase both will be present in the string w. 
Array b and Array x contain corresponding redefined ASCII values.
For each i, 0<=ib[i] contain redefined ASCII value of character x[i].


Example 1:
Input:
W = abcde
N = 1
X[] = { 'c' }
B[] = { -1000 }
Output:
de
Explanation:
Substring "de" has the
maximum sum of ascii value,
including c decreases the sum value



Example 2:
Input:
W = dbfbsdbf 
N = 2
X[] = { 'b','s' }
B[] = { -100, 45  }
Output:
dbfbsdbf
Explanation:
Substring "dbfbsdbf" has the maximum
sum of ascii value.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxSum() 
which takes string W, character array X, integer array B, integer N as length of array X and B as input parameters and
returns the substring with the maximum sum of ascii value.
 

Expected Time Complexity: O(|W|)
Expected Auxiliary Space: O(1)
*/



class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here   
          unordered_map<char,int> mp;
          
          for(int i=0;i<n;i++){
              mp[x[i]]=b[i];
          }
          vector<int> ans;
          int val=INT_MIN;
          int l=0;
          int sum=0;
          for(int r=0;r<w.length();r++){
              if(mp.find(w[r])==mp.end()){
                  sum+=w[r];
              }
              else{
                  sum+=mp[w[r]];
              }
              if(val<sum){
                val=sum;
                ans.clear();
                ans.push_back(l);
                ans.push_back(r);
              }
              while(l<=r && sum<0){
                  if(mp.find(w[l])==mp.end()){
                      sum-=w[l];
                  }
                  else{
                      sum-=mp[w[l]];
                  }
                  l++;
              }
          }
          int i=ans[0],j=ans[1];
          return w.substr(i,j-i+1);
      }
};
