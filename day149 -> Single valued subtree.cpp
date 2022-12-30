/*
Given a binary tree, count the number of Single Valued Subtrees. A Single Valued Subtree is one in which all the nodes have same value. 



Example 1
Input :
              5
             / \
            1   5
           / \   \
          5   5   5
Output : 4
Explanation : 
There are 4 subtrees with single values.



Example 2:
Input:
              5
             / \
            4   5
           / \   \
          4   4   5   
Output: 5
Explanation: 
There are five subtrees with single values.


Your task :
You don't have to read input or print anything. Your task is to complete the function singlevalued() 
which takes the root of the tree as input and returns the count of single valued subtrees.
 
Expected Time Complexity : O(n)
Expected Auxiliary Space : O(n)
 
Constraints :
1 <= n <= 10^5
*/


/* Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

class Solution
{
    public:
    int cnt;

    int solve(Node * root,Node* prev){

        if(root==NULL){
          return 1;
        }

        int l=solve(root->left,root);
        int r=solve(root->right,root);

        if(l==1&&r==1){
           cnt++;
        }

        return root->data==prev->data&&l==1&&r==1;

    }

    int singlevalued(Node *root)

    {

        cnt=0;
        Node* prev;
        solve(root,root);
        return cnt;

    }

    
};
