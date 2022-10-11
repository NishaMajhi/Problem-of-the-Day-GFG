/*
An encoded string (s) is given, the task is to decode it. 
The encoding pattern is that the occurance of the string is given at the starting of the string and each string is enclosed by square brackets.


Example 1:
Input: s = 1[b]
Output: b
Explaination: 'b' is present only one time.



Example 2:
Input: s = 3[b2[ca]]
Output: bcacabcacabcaca
Explaination: 2[ca] means 'ca' is repeated 
twice which is 'caca' which concatenated with 
'b' becomes 'bcaca'. This string repeated 
thrice becomes the output.


Your Task:
You do not need to read input or print annything. 
Your task is to complete the function decodedString() which takes s as input parameter and returns the decoded string.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 ≤ |s| ≤ 103 
*/


class Solution{
public:
    string decodedString(string s){
        
        stack<string> st1;
        stack<int> st2;
        string currString="", prevString="";
        int Currnum=0,prevNum;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='['){
                st1.push(currString);
                st2.push(Currnum);
                currString ="";
                Currnum=0;
            }
            else if(s[i]==']'){
                prevNum = st2.top();
                st2.pop();
                prevString = st1.top();
                st1.pop();
                string tmp="";

                for(int j=0;j<prevNum;j++){
                    tmp += currString;
                }

                currString = prevString + tmp;
            }
            else if(s[i]>='0' && s[i]<='9'){
                Currnum = Currnum*10+(s[i]-'0');
            }
            else{
                currString += s[i];
            }

        }
        return currString;

    }


};
