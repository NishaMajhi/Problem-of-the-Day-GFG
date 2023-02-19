/*
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed than the given input will form BST, except for 2 nodes that will be wrong.
 
 
Example 1:
Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1
Explanation:
 
 
Example 2:
Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1 
Explanation: 
By swapping nodes 11 and 10, the BST 
can be fixed.


Your Task:
You don't need to take any input. Just complete the function correctBst() that takes root node as parameter. 
The function should return the root of corrected BST. BST will then be checked by driver code and 0 or 1 will be printed.

Expected Time Complexity : O(Number of nodes)
Expected Auxiliary Space : O(logN), N = number of nodes
 
Constraints:
1 <= Number of nodes <= 10^5
*/


/*struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
    void Inorder(Node* root,vector<Node*>& nodes){
        
        if(root==NULL)
           return;
        Inorder(root->left,nodes);
        nodes.push_back(root);
        Inorder(root->right,nodes);
    }
    
    struct Node *correctBST(struct Node *root) {
        
        vector<Node*> nodes;
        Inorder(root,nodes);
        
        Node* first=NULL,*second=NULL;
        
        for(int i=1;i<nodes.size();i++){
            
            if(nodes[i-1]->data > nodes[i]->data){
                
                if(first==NULL){
                   first=nodes[i-1];
                }
                second=nodes[i];
            }
        }
        int temp=first->data;
        first->data=second->data;
        second->data=temp;
        
        return root;
    }
};
