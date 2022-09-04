/*

Write a program that receives a number n as input and prints it in the following format as shown below.
Like for n = 2 the pattern will be:
1*2*5*6
--3*4

Example 1:

Input: n = 3
Output: 
1*2*3*10*11*12
--4*5*8*9
----6*7
Explaination: If the pattern shown in question 
is followed, this will be the output.

Your Task:
You do not need to read input or print anything. 
Your task is to complete the function pattern() which takes n as input parameter and 
returns a list of string where each string denotes a new line of the pattern.

Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 ≤ n ≤ 70  
*/

class Solution{
public:
    vector<string> pattern(int n){
        vector<string> ans;
        string temp;
        int j = 0;
        int k = 1;
        int z = 1;
        int sum = n*(n+1)+1;
        for(int i=n;i>=1;i--){
            for(int l=0;l<j;l++) temp += '-';
            j += 2;
            sum -= n;
            // cout<<sum<<endl;
            for(int l=1;l<=i;l++){
                temp +=  to_string(k);
                temp += '*';
                k++;
            }
            int m = sum;
            for(int l=1;l<=i;l++){
                temp += to_string(m);
                if(l != i) temp += '*';
                m++;
            }
            sum += z;
            z++;
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
