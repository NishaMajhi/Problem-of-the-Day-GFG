/*
Given a string consisting of lowercase english alphabets. Find the repeated character present first in the string.

Example 1:

Input:
S = "geeksforgeeks"

Output: g

Explanation: g, e, k and s are the repeating
characters. Out of these, g occurs first. 


Example 2:

Input: 
S = "abcde"

Output: -1

Explanation: No repeating character present.

Your Task:
You don't need to read input or print anything. 
Your task is to complete the function firstRep() which takes the string S as input and returns the the first repeating character in the string.
In case there's no repeating character present, return '#'.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105
*/


#include<bits/stdc++.h>
using namespace std;


class Solution
{
  public:
    char firstRep (string s)
    {
         int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[s[i]]>1){
                return s[i];
            }
        }
        return '#';
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
