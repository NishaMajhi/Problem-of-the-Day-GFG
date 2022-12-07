/*
Given a BST and an integer K. Find the Kth Smallest element in the BST using O(1) extra space. 


Example 1:
Input:
      2
    /   \
   1     3
K = 2
Output: 2
Explanation: 2 is the 2nd smallest element in the BST


Example 2:
Input:
        2
      /  \
     1    3
K = 5
Output: -1
Explanation: There is no 5th smallest element in the BST as the size of BST is 3
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function KthSmallestElement()
which takes the root of the BST and integer K as inputs and return the Kth smallest element in the BST, if no such element exists return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1<=Number of nodes<=100000
*/


/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    void inorder(Node *root,vector<int> &v){
        
        if(root == NULL)
           return;
           
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        
        vector<int> v;
        inorder(root,v);
        int n = v.size();
        if(K > n)
           return -1;
        return(v[K-1]);
    }
};
