/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 


Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->22->28->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)
 

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter
and returns the head of flattened link list.
 

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)
 

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103
*/


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution {
public:


    Node *mergeList(Node *root1,Node *root2){
        
        // base cases
        // if root1 is empty
        if(root1==NULL)
           return root2;
        //   if root2 is empty
        if(root2==NULL)
           return  root1;
        
        Node* ans;
        // if root1 data is less then data of root2 then
        // we will store root1 and called the merge function again for root1->bottom 
        if(root1->data < root2->data){
            ans = root1;
            ans->bottom = mergeList(root1->bottom,root2);
        }
        
        // if root2 data is less then data of root1 then
        // we will store root2 and called the merge function again for root2->bottom 
        else{
            ans = root2;
            ans->bottom = mergeList(root1,root2->bottom);
        }
        
        // return answer root
        return ans;
        
    }
    
    
    Node *flatten(Node *root){
        
        //base case 
        //if current root or root->next is null return current root
        if(root==NULL || root->next==NULL)
            return root;
        
        //firstly -> break the list till last last sub-list then call merge the sub-lists
        // in this case the last sublist and second last sublist merged first then go previous
        return mergeList(root,flatten(root->next));
    }
};

