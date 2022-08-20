/*
Given two strings denoting non-negative numbers X and Y. Calculate the sum of X and Y.


Example 1:

Input:
X = "25", Y = "23"
Output:
48
Explanation:
The sum of 25 and 23 is 48.



Example 2:

Input:
X = "2500", Y = "23"
Output:
2523
Explanation:
The sum of 2500 and 23 is 2523.

Your Task:
Your task is to complete the function findSum() which takes two strings as inputs and
returns the string without leading zeros.You do not need to take any input or print anything.


Expected Time Complexity: O(|X| + |Y|)
Expected Auxiliary Space: O(1)


Constraints:
1 <= |X|, |Y| <= 105
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findSum(string X, string Y) {
        
        int i = X.size()-1;
        int j = Y.size()-1;
        int carry = 0;
        string ans = "";
        
        while(i >= 0 && j >= 0){
            int sum = X[i]-'0' + Y[j]-'0' + carry;
            int d = sum%10+'0';
            carry = sum/10;
            ans.push_back(d);
            i--;j--;
        }
        
        while(i >= 0){
            int sum = X[i]-'0' + carry;
            int d = sum%10+'0';
            carry = sum/10;
            ans.push_back(d);
            i--;
        }
        
        while(j >= 0){
            int sum = Y[j]-'0' + carry;
            int d = sum%10+'0';
            carry = sum/10;
            ans.push_back(d);
            j--;
        }
        if(carry>0){
            ans.push_back(carry+'0');
        }
        while(ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size() <= 0)
           ans = "0";
           
        return ans;
    }
};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
