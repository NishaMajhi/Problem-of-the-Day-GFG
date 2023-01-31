/*
Given two strings A and B. Find minimum number of times A has to be repeated such that B is a Substring of it.
If B can never be a substring then return -1.
 

Example 1:
Input:
A = "abcd"
B = "cdabcdab"
Output:
3
Explanation:
Repeating A three times (abcdabcdabcd),
B is a substring of it. B is not a substring
of A when it is repeated less than 3 times.



Example 2:
Input:
A = "ab"
B = "cab"
Output :
-1
Explanation:
No matter how many times we repeat A, we can't
get a string such that B is a substring of it.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minRepeats() which takes 2 strings A, and B respectively
and returns the minimum number of times A has to be repeated such that B is a substring of it. Return -1 if it's not possible.


Expected Time Complexity: O(|A| * |B|)
Expected Auxiliary Space: O(|B|)


Constraints:
1 ≤ |A|, |B| ≤ 103
String A and B consists of lower case alphabets
*/


class Solution {
  public:
    int minRepeats(string A, string B) {
        
        int s1 = B.size();
        string temp = A;
        int repCount = 1;
        
       // we will ADD input A into current A till current A.size() < input string B.size()      
        while(A.size() < s1){
            A+=temp;
            repCount++;
        }
        // find function use to check first occurance of substring
        // input A=abcd B=abcdabcd
        // this line will return 2
        if(A.find(B)!=-1)
          return repCount;
        
        // if the current size of A string having some character missing of B string
        // again ADD input string A to current string A and check
        A+=temp;
        repCount++;
        
        // find function use to check first occurance of substring
        if(A.find(B)!=-1)
          return repCount;
         
        return -1;
    }
};
