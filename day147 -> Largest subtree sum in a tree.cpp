/*
Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.


Example 1:
Input:
              1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output: 28
Explanation: 
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.


Example 2:
Input:
               1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output: 7
Explanation: 
Subtree with largest sum is : 
  -2
 /  \ 
4    5
Also, entire tree sum is also 7.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findLargestSubtreeSum() 
which takes the root of a binary tree and returns an integer.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 10^5
-10^3 <= tree.val <= 10^3
*/



class Solution {
  public:
    // Function to find largest subtree sum.
    void sum(Node* root,unordered_map<Node*,int>&helper){
        if(root==NULL)
           return;
        
        sum(root->left,helper);
        sum(root->right,helper);
        
        if(root->left!=NULL && root->right!=NULL)
            helper[root]=root->data+helper[root->left]+helper[root->right];
        else if(root->left==NULL && root->right!=NULL)
            helper[root]=root->data+helper[root->right];
        else if(root->left!=NULL && root->right==NULL)
            helper[root]=root->data+helper[root->left];
        else
            helper[root]=root->data;
    }
    
    int findLargestSubtreeSum(Node* root)
    {
        if(root==NULL)
           return 0;
           
        unordered_map<Node*,int> helper;
        sum(root,helper);
        int maxi=INT_MIN;
        
        for(auto it:helper)
           maxi=max(maxi,it.second);
        
        return maxi;
    }
};
