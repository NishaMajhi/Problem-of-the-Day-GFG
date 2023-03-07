/*
Given a Binary Tree having positive and negative nodes. Find the maximum sum of a level in the given Binary Tree.



Example 1:
Input :               
             4
          /    \
         2     -5
        / \    / \
      -1   3  -2  6

Output: 6

Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6




Example 2:
Input :          
            1
          /   \
         2     3
        / \     \
       4   5     8
                / \
               6   7  

Output :  17

Explanation: Maximum sum is at level 2.


Your Task:  
You dont need to read input or print anything. Complete the function maxLevelSum() which takes root node as input parameter and 
returns the maximum sum of any horizontal level in the given Binary Tree.

Expected Time Complexity: O(N), where N is no of node.
Expected Auxiliary Space: O(W), Where W is the max width of the tree.


Constraints:
1 ≤ N ≤ 104
*/


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution{
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        
        queue<Node*> pendingNodes;
        int temp=0,ans=INT_MIN;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        while (!pendingNodes.empty())
        {
            Node *front = pendingNodes.front();
            pendingNodes.pop();
            if (front != NULL)
            {
                temp+=front->data;
                if (front->left != NULL)
                {
                    pendingNodes.push(front->left);
                }
                if (front->right != NULL)
                {
                    pendingNodes.push(front->right);
                }
            }
            else
            {
                ans=max(ans,temp);
                if (pendingNodes.empty())
                {
                    break;
                }
                pendingNodes.push(NULL);
                temp=0;
            }
        }
        return ans;
    }
};
