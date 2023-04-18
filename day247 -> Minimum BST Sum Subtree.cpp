/*
Given a binary tree and a target, find the length of minimum sub-tree with the given sum equal to target which is also a binary search tree.



Example 1:
Input:
           13
         /    \
       5       23
      / \      / \
     N   17   N   N
         /
        16
Target: 38
Output: 3
Explanation: 5,17,16 is the smallest subtree
with length 3.
 
 

Example 2:
Input:
             7
           /   \
          N    23
             /   \
            10    23
           /  \   / \
          N   17 N   N
Target: 73
Output: -1
Explanation: No subtree is bst for the given target.



Your Task:  
You don't need to read input or print anything. Your task is to complete the function minSubtreeSumBST() which takes the tree root and
target as input parameters and returns length of largest subtree having sum equal to the target which is also a binary search tree.

Expected Time Complexity:O(n)
Expected Space Complexity:O(1) 

Constraints:
1 <= N <= 10^5
*/


class Solution {
public:

    int minSize=INT_MAX;
    vector<int> solve(int target,Node *root){
        
        if(root==NULL){
           //index0->length , index1->so far sum , index2->so far min data , index3->so far max data
           return {0,0,INT_MAX,INT_MIN}; 
        }
        
        //we are calculating sum of left subtree and right subtree
        vector<int> leftSubTree = solve(target,root->left);
        vector<int> rightSubTree = solve(target,root->right);
        
        if(root->data > leftSubTree[3] && root->data < rightSubTree[2]){
            
            int sum = leftSubTree[1] + rightSubTree[1] + root->data;
            int length=leftSubTree[0] + rightSubTree[0]+1;
            
            if(target==sum){
                minSize = min(minSize,length);
            }
            
            return {length,sum,min(root->data,leftSubTree[2]) , max(root->data,rightSubTree[3])};
        }
        
        return {0,0,INT_MIN,INT_MAX};
    }
    
    int minSubtreeSumBST(int target, Node *root) {
       
       solve(target,root);
       
       if(minSize==INT_MAX)
          return -1;
        
        return minSize;
        
    }
};
