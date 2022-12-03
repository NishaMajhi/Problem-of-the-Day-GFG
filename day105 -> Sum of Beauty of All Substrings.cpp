/*
Given a string S, return the sum of beauty of all its substrings.
The beauty of a string is defined as the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of string "aaac" is 3 - 1 = 2.


Example 1:
Input:
S = "aaac"
Output:
3
Explanation: The substrings with non - zero beauty are ["aaac","aac"] where beauty of "aaac" is 2 and beauty of "aac" is 1.
 

Example 2:
Input:
S = "geeksforgeeks"
Output:
62
Explanation: There are 91 substrings of the given strings. Like, the beauty of substring "geek" is 1. In this way the sum of beauties of all substrings are 62.


Your Task:
You don't need to read input or print anything. Your task is to complete the function beautySum() which takes 
string S as input paramters and returns the sum of beauty of all its substrings. 

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(1)

Constraints: 
1 ≤ |S| ≤ 500
S only contains lower case alphabets.
*/




class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int i,j,l,k;
        int sum=0;
        l=s.length();
        for (i=0;i<l;i++) { 
            int most=0,least,n;
            char arr[128]={0};
            for (j=i;j<l;j++) { 
                arr[s[j]]++;
                n=arr[s[j]];
                if (n>most) { 
                    most=n;
                }
                least=10000;
                for (k=97;k<=122;k++) { 
                    if (arr[k]>0 && arr[k]<least) { 
                        least=arr[k];
                    }
                }
                sum+=most-least;
            }
        }
        return sum;

    }

};