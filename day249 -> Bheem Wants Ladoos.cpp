/*
Chhota Bheem wants to eat the maximum number of ladoos in Dholakpur on Independence Day.
The houses in Dholakpur are arranged in the form of a binary tree and have ladoos the same as their house number. 
Chhota Bheem is standing at his home initially. 
Find the maximum ladoos he can eat if he can go to houses within a maximum distance k from his house. 
The number of ladoos at his home should also be included in the sum.

Note: Every house has distinct ladoos in it. 



Example 1:
Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
home = 9, K = 1
Output:
22
Explanation:
Initially Bheem at 9, so sum = 9
In 2nd move he went to 5, sum=9+5=14
In 3rd move he went to 7, sum=14+7=21
In 4th move he went to 1, sum=21+1=22
So within K distance bheem can get 22 ladoos.  



Example 2:
Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
home = 40, K = 2
Output:
113
Explanation:
Initially Bheem at 40, so sum = 40
In 2nd move he went to 19, sum=40+19=59
In 3rd move he went to 4, sum=59+4=63
In 4th move he went to 50, sum=63+50=113
So within K distance bheem can get 113 ladoos.


Your Task:
You don't need to read input or print anything. Complete the function ladoos() which takes the root of the tree, home, and K  as input parameters 
and returns the maximum number of ladoos he can eat.

Expected Time Complexity: O(N), where N is no. of nodes
Expected Space Complexity: O(1)

Constraints:
1 ≤ N, Home ≤ 105
1 ≤ K ≤ 20
*/


/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
    private:
    
    void make_parents(Node *root, int home, unordered_map<Node *, Node *> &parent, Node *&bheem) {
        
        if(!root) return;
        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            if(p->data == home) bheem = p;
            
            if(p->left) {
                parent[p->left] = p;
                q.push(p->left);
            }
            
            if(p->right) {
                parent[p->right] = p;
                q.push(p->right);
            }
        }
        
    }
    
    public:
    int ladoos(Node* root, int home, int k) {
        if(!root) 
            return 0;
        
        unordered_map<Node *, Node *> parent;
        Node *bheem = NULL;
        make_parents(root, home, parent, bheem);
        
        queue<Node *> q;
        unordered_map<Node *, bool> visited;
        
        q.push(bheem);
        visited[bheem] = true;
        
        int sum = bheem->data, curr_lvl = 0;
        
        while(!q.empty()) {
            int n = q.size();
            if(curr_lvl == k) return sum;
            
            for(int i = 0; i < n; i++) {
                auto p = q.front();
                q.pop();
                
                if(p->left and !visited[p->left]) {
                    sum += p->left->data;
                    q.push(p->left);
                    visited[p->left] = true;
                }
                
                if(p->right and !visited[p->right]) {
                    sum += p->right->data;
                    q.push(p->right);
                    visited[p->right] = true;
                }
                
                if(parent[p] and !visited[parent[p]]) {
                    sum += parent[p]->data;
                    q.push(parent[p]);
                    visited[parent[p]] = true;
                }
            }
            
            curr_lvl++;
        }
        
        return sum;
    }
    
};
