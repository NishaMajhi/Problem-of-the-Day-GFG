/*
Given a number k and string num of digits (0 to 9) denoting a positive integer.
Find a string denoting the lowest integer number possible by removing k digits from num, without changing their order.
Note: num will not contain any leading zero.


Example 1:
Input:
k = 2
num = "143729"
Output: "1329"
Explanation: 1329 is the minimum number
possible after removing '4' and '7'.
 

Example 2:
Input:
k = 3
num = "10056"
Output: "0"
Explanation: 0 is the minimum number
possible after removing '1' , '5' and '6'.
 

Your Task:  
You dont need to read input or print anything. Complete the function buildLowestNumber() which accepts string num and integer k as input parameters 
and returns a string denoting the smallest integer possible after removing k digits from num without changing the order.


Expected Time Complexity: O(Length of num) 
Expected Auxiliary Space: O(Length of num) 


Constraints:
1 <= Length of num <= 105
0 <= k < Length of num
*/



string formMin(string s, int& k) {
    
    stack<char> st;

    for(int i = 0; i < s.length(); i++) {
        if(st.empty() || st.top() <= s[i])
            st.push(s[i]);
        else {
            while(!st.empty() && k > 0 && st.top() > s[i]) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
    }
    
    while(k > 0) {
        st.pop();
        k--;
    }
    
    string ans = "";

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    ans.erase(0, ans.find_first_not_of('0'));
    
    return (ans.length() == 0) ? "0" : ans;
}


string buildLowestNumber(string num, int k){
    
    if(k > num.length())
       return "0";
       
    return formMin(num,k);
}
