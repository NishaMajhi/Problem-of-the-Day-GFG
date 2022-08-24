/*

Given a string S containing only digits, 
Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses 
and takes only a string S as its only argument.
Note: Order doesn't matter. A valid IP address must be in the form of A.B.C.D, 
where A, B, C, and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.


For string 11211 the IP address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1



Example 1:

Input:
S = 1111
Output: 1.1.1.1



Example 2:

Input:
S = 55
Output: -1

Your Task:

Your task is to complete the function genIp() which returns a vector containing all possible combinations of valid IPv4 IP addresses
or -1 if no such IP address could be generated through the input string S, the only argument to the function.

Expected Time Complexity: O(N * N * N * N)
Expected Auxiliary Space: O(N * N * N * N)

Constraints:
1<=N<=16
here, N = length of S.
S only contains digits(i.e. 0-9)
*/




class Solution{
    int n;
    vector<string> res;
  public:
    void rec(int ind, int partitions, string curr, string s){
        if(ind == n){
            if(partitions == 4)   curr.pop_back(), res.push_back(curr);
            return;
        }
        if(partitions > 3)  return;
        
        for(int i=ind; i<ind+3 && i<n; i++){
            string sub = s.substr(ind, i-ind+1);
            if(stoi(sub) > 255 or (sub.length() > 1 && sub[0] == '0'))        continue;
            
            string ne = curr + sub + '.';
            rec(i+1, partitions+1, ne, s);
        }
    }
    vector<string> genIp(string &s) {
        // Your code here
        n = s.length();
        if(n < 4)   return {};
        rec(0, 0, "", s);
        return res;
    }

};
