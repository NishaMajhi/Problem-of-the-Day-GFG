/*
Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.


Example 1:
Input:
N = 2
arr = {2,1}
Output: {1}
Explaination: 1 is the only leaf node.


Example 2:
Input:
N = 3
Arr = {3, 2, 4}
Output: {2, 4}
Explaination: 2, 4 are the leaf nodes.


Your Task:
You don't need to read input or print anything. Your task is to complete the function leafNodes() which
takes the array arr[] and its size N as input parameters and returns the leaf nodes of the tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 103
*/


class Solution {
  public:
    vector<int> leaves;
    void rec(int l, int r, int arr[])
    {
        if(l>r) return;
        if(l==r)
        {
            leaves.push_back(arr[l]);
            return;
        }
        int i;
        for(i=l+1;i<=r;i++)
        {
            if(arr[i]>arr[l]) break;
        }
        rec(l+1,i-1,arr);
        rec(i,r,arr);
    }
    
    vector<int> leafNodes(int arr[],int N) {
        // code here
        int l=0,r=N-1;
        rec(l,r,arr);
        return leaves;
    }
};
