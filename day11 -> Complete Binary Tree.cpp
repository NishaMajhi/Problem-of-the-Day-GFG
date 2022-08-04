/*
Given a Binary Tree, write a function to check whether the given Binary Tree is Complete Binary Tree or not.
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled,
and all nodes are as far left as possible.


Example 1:
Input:
       1
      / \
     2   3
Output:
Complete Binary Tree


Example 2:
Input:
              1
            /   \
          2      3
           \    /  \
            4  5    6
Output:
Not Complete Binary Tree


Constraints:
1<=Number of Node<=100
0 <= Data of a node <= 106

Your Task:
You don't need to take input.
Just complete the function isCompleteBT() that takes root node as a parameter and returns true, if the tree is Complete else returns false.
*/


#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
    

class Solution{
public:    
    bool isCompleteBT(Node* root){
        
        bool flag = false;
        
        //using level Order Traversal
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            
            //take out front node of queue
            Node *t = q.front();
            q.pop();
            
            //check wheater it has any left child or not
            if(t->left){
                
                if(flag == true)
                   return false;
                q.push(t->left);
            }    
            else{
                flag = true;
            }
            
            //check wheater it has any right child or not
            if(t->right){
                
                if(flag == true)
                   return false;
                q.push(t->right);
            }    
            else{
                flag = true;
            }
            
        }
        
        return true;
    }
};


int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		Solution ob;
        if(ob.isCompleteBT(root)){
            printf ("Complete Binary Tree\n");
        }
        else{
            printf ("Not Complete Binary Tree\n");
        } 
    }
    return 0;
}
