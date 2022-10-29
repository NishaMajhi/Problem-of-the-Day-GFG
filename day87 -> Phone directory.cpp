/*
Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s.
The task is to implement a search query for the phone directory.
Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) 
that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. 
Please refer the explanation part for better understanding.

Note: If there is no match between query and contacts, print "0".


Example 1:

Input: 
n = 3
contact[] = {"geeikistest", "geeksforgeeks", 
"geeksfortest"}
s = "geeips"

Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0

Explaination: By running the search query on 
contact list for "g" we get: "geeikistest", 
"geeksforgeeks" and "geeksfortest".
By running the search query on contact list 
for "ge" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "gee" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "geei" we get: "geeikistest".
No results found for "geeip", so print "0". 
No results found for "geeips", so print "0".


Your Task:
Youd do not need to read input or print anything. Your task is to complete the function displayContacts() 
which takes n, contact[ ] and s as input parameters and returns a list of list of strings for required prefixes. 
If some prefix has no matching contact return "0" on that list.

Expected Time Complexity: O(|s| * n * max|contact[i]|)
Expected Auxiliary Space: O(n * max|contact[i]|)

Constraints:
1 ≤ T ≤ 100, T = number of test cases
1 ≤ n ≤ 50
1 ≤ |contact[i]| ≤ 50
1 ≤ |s| ≤ 6 
*/



struct TrieNode
{
    TrieNode *child[26];
    bool isLast;
};

TrieNode *root = NULL;

class Trie
{
    public:
     
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s)
    {
        TrieNode *curr = root;
        
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            if (curr->child[index] == NULL)
            {
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }

        curr->isLast = true;
    }

    void displayContactsUtil(TrieNode *curNode, string prefix, vector<string> &vec)
    {
        if (curNode->isLast) vec.push_back(prefix);
        for (char i = 'a'; i <= 'z'; i++)
        {
            TrieNode *nextNode = curNode->child[i - 'a'];
            if (nextNode != NULL) displayContactsUtil(nextNode, prefix + (char)i, vec);
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> res;
        TrieNode *prevNode = root;
        string prefix = "";
        int len = s.length();
        int i;
        for (i = 0; i < len; i++)
        {
            vector<string> v;
            prefix += (char)s[i];
            char lastChar = prefix[i];
            TrieNode *curNode = prevNode->child[lastChar - 'a'];
            if (curNode == NULL)
            {
                v.push_back("0");
                res.push_back(v);
                i++;
                break;
            }
            displayContactsUtil(curNode, prefix, v);
            prevNode = curNode;
            res.push_back(v);
        }
        for (; i < len; i++)
        {
            vector<string> v;
            v.push_back("0");
            res.push_back(v);
        }
        return res;
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
    	Trie op;
    	
    	//inserting all the contacts
        for (int i = 0; i < n; i++) op.insert(contact[i]);
        
        vector<vector<string>> ans = op.displayContacts(n, contact, s);    
        return ans;
    }
};
