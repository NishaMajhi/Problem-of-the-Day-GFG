/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place.
The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL.
The order of nodes in DLL must be same as Inorder of the given Binary Tree.
The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.



Example 1:

Input:
      1
    /  \
   3    2

Output:
3 1 2 
2 1 3 

Explanation: DLL would be 3<=>1<=>2



Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60

Output:
40 20 60 10 30 
30 10 60 20 40

Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30.


Your Task:
You don't have to take input. Complete the function bToDLL() that takes root node of the tree as a parameter and
returns the head of DLL . The driver code prints the DLL both ways.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for the recursion stack.

Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105


*/


/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
    public: 
    
    //create prev for keeping travk of previos node
    Node *prev = NULL;
    //create head to  store head of Doubly Linked List
    Node *head = NULL;
    
    void inorder(Node *root){
        
        //if there is nothing in root
        if(root == NULL)
           return ;
         
         //call inorder funtion towards its left 
        inorder(root->left);
        
        //if this is the left most nodethen it will be head of Doubly Linked Lsit
        if(prev == NULL)
          head = root;
          
         //otherwise set current node->left = previous node 
         //and previous node->right = current node
        else{
           root->left = prev;
           prev->right = root;
        }
        
        //set current node as previos node for further List node
        prev = root;
        
        //call inorder function towards its right
        inorder(root->right);
    }
    
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(root == NULL)
           return root;
        
        //call inorder function  
        inorder(root);
        
        //return head of Doubly Linked List
        return head;
    }
};
