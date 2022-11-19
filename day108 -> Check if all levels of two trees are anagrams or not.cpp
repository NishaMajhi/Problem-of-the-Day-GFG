/*
Given two binary trees, the task is to check if each of their levels are anagrams of each other or not. 


Example 1:
Input:

Output: 1

Explanation: 
Tree 1:
Level 0 : 1
Level 1 : 3, 2
Level 2 : 5, 4

Tree 2:
Level 0 : 1
Level 1 : 2, 3
Level 2 : 4, 5

As we can clearly see all the levels of above two binary trees 
are anagrams of each other, hence return true.


Example 2:
Input:

Output: 0
Explanation: 

Tree 1:
Level 0 : 1
Level 1 : 2, 3 
Level 2 : 5, 4 

Tree 2: 
Level 0 : 1 
Level 1 : 2, 4 
Level 2 : 5, 3 

As we can clearly see that level 1 and leve 2 are not anagrams of each other, hence return false.


Your Task:  
You don't need to read input or print anything. Your task is to complete the function areAnagrams()
which takes the root of two trees as input and returns an 1 if all the levels are anagrams, else returns 0 as output.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 104
1 <= tree.val <= 109
*/




class Solution{
    public:
    void lvlOrder(Node *root,vector<vector<int>>&v){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int>curlevel;
            for(int i=0;i<sz;i++){
                Node*t=q.front();
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                curlevel.push_back(t->data);
            }
            v.push_back(curlevel);
        }
    }


    bool areAnagrams(Node *root1, Node *root2){
       if(!root1 && !root2) return true;
       vector<vector<int>> ans1;
       vector<vector<int>> ans2;
       //level order traversal
       lvlOrder(root1,ans1);
       lvlOrder(root2,ans2);
       // then check for if both the vectors have same elements
       if(ans1.size()!=ans2.size()) return false;
       for(int i=0;i<ans1.size();i++){
           if(ans1[i].size()!=ans2[i].size()) return false;
           for(int j=0;j<ans1[i].size();j++){
               if(find(ans2[i].begin(),ans2[i].end(),ans1[i][j])!=ans2[i].end()){
                   continue;
               }
               else{
                   return false;
               }
           }
       }
       return true;
    }
};
