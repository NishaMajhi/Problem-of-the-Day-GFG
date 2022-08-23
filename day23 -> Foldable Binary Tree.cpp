/*
Given a binary tree, check if the tree can be folded or not.
A tree can be folded if left and right subtrees of the tree are structure wise same.
An empty tree is considered as foldable.



Consider the below trees:
(a) and (b) can be folded.
(c) and (d) cannot be folded.


(a)
       10
     /    \
    7      15
     \    /
      9  11
(b)
        10
       /  \
      7    15
     /      \
    9       11
(c)
        10
       /  \
      7   15
     /    /
    5   11
(d)
         10
       /   \
      7     15
    /  \    /
   9   10  12
 


Example 1:

Input:
     10
    /    \
   7     15
 /  \   /  \
N   9  11   N
Output:Yes
Explaination:Structure of every left and right subtree are same. 



Example 2:

Input:
      10
    /    \
   7     15
 /  \   /  \
5   N  11   N
Output: No
Explaination: 7's left child is not NULL and right child is NULL. That's why the tree is not foldable. 


Your Task:
The task is to complete the function isFoldable() that takes root of the tree as input and
returns true or false depending upon whether the tree is foldable or not.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= n <= 103
1 <= data of node <= 104
*/





/* A binary tree node has data, pointer to left child
and a pointer to right child */
/*struct node
{
    int data;
    struct node* left;
    struct node* right;
    
    node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

bool checkFoldable(Node *leftTree,Node *rightTree){
    
    if(leftTree ==  NULL && rightTree == NULL)
       return true;
    else if(leftTree == NULL || rightTree == NULL)
       return false;
     
    bool leftPart = checkFoldable(leftTree->left,rightTree->right);
    bool rightPart = checkFoldable(leftTree->right,rightTree->left);
    
    if(leftPart && rightPart)
       return true;
    else  return false;
}

//Function to check whether a binary tree is foldable or not.
bool IsFoldable(Node* root)
{
    if(!root) 
       return true;
       
    return checkFoldable(root->left,root->right);
}
