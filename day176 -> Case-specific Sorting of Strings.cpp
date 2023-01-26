/*
Given a string S consisting of only uppercase and lowercase characters. 
The task is to sort uppercase and lowercase letters separately such that
if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted
and vice versa.



Example 1:
Input:
N = 12
S = defRTSersUXI
Output: deeIRSfrsTUX
Explanation: Sorted form of given string
with the same case of character as that
in original string is deeIRSfrsTUX



Example 2:
Input:
N = 6
S = srbDKi
Output: birDKs
Explanation: Sorted form of given string
with the same case of character will
result in output as birDKs.


Your Task:
You only need to complete the function caseSort that takes a string str and length of the string n and returns sorted string.

Expected Time Complexity: O(Nlog(N)).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
*/



class Solution{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n){
        
        string result;
        
        vector<int> lower_freq(26,0);
        vector<int> upper_freq(26,0);  
        
        for(int i=0;i<str.size();++i){
            
            if(str[i]>='a' && str[i]<='z') lower_freq[str[i]-'a']++;
            else                           upper_freq[str[i]-'A']++;
            
        }
        
        int upper_idx=0;
        int lower_idx=0;
        
        for(int i=0;i<str.size();++i){
            
            while(lower_idx<26 && lower_freq[lower_idx]==0) lower_idx++;
            while(upper_idx<26 && upper_freq[upper_idx]==0) upper_idx++;
            
            if(str[i]>='a' && str[i]<='z') {
                result.push_back(lower_idx+'a');
                lower_freq[lower_idx]--;
             }
            else{
                 result.push_back(upper_idx+'A');
                 upper_freq[upper_idx]--;
                }                          

        }
        return result;
    
    }
};
