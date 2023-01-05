/*
Given an array of strings arr[]. You have to find the longest string which is lexicographically smallest 
and also all of its prefix strings are already present in the array.

 

Example 1:
Input: ab a abc abd
Output: abc
Explanation: We can see that length of the longest 
string is 3. And there are two string "abc" and "abd"
of length 3. But for string "abc" , all of its prefix
"a" "ab" "abc" are present in the array. So the
output is "abc".



Example 2:
Input: ab a aa abd abc abda abdd abde abdab
Output: abdab
Explanation: We can see that each string is fulfilling
the condition. For each string, all of its prefix 
are present in the array.And "abdab" is the longest
string among them. So the ouput is "abdab".
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function longestString()
which takes the array arr[] as input parameter and returns the longest string which is also lexicographically smallest.
And if there is no such string return empty string.
 

Expected Time Complexity: O(NlogN)
Expected Space Complexity: O(N)

 

Constraints:
1 <= length of arr[] <= 103
1 <= arr[i].length <=30
*/


class Solution{
public:
    string longestString(vector<string> &words){
      
        //take a set to insert all unique words
        set<string> s;
        for(auto it:words){
            s.insert(it);
        }
        
        //sort the array of string to take out words in a sorted manner
        sort(words.begin(),words.end());
        //take a string to store final answer
        string ans;
        
        //loop to check every words
        for(auto it:words){
            //take a string to store current word
            string str = it;
            //take a string to compare
            string temp;
            //boolean variable to check whether already exist or not
            bool flag = true;
            //loop will take single character from current word and check 
            // whether current formed word present in the set or not 
            for(int j=0;j<str.size();j++){
                temp += str[j];
                if(!s.count(temp)){
                    flag = false;
                    break;
                }
            }
            // current formed word is present in the array or its size is greater then previous word
            // then current formed word would be our new answer
            if(flag == true && str.size()>ans.size()){
                ans = str;
            }
        }
        
        return ans;
    }
};
