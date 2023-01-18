/*
Given a singly linked list of N nodes. Find the first node of the loop if the linked list has a loop.
If a loop is present return the node data of the first node of the loop else return -1.


Your Task:
The task is to complete the function findFirstNode() which contains reference to the head as only argument.
This function should return the value of the first node of the loop if the linked list contains a loop, else return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Data on Node <= 106 
0 <= pos <= N
*/


/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // using extra space
        set<Node*> s;
        Node *curr = head;
        while(curr != NULL){
            if(s.find(curr) != s.end()){
                return curr->data;
            }
            else{
                s.insert(curr);
            }
            curr = curr->next;
        }
        
        return -1;
        
        // without using extra space
    //     Node *fast = head;
    //     Node *slow = head;
    //   // to find whether linked list contain loop or not   
    //     while(fast->next && fast->next->next){
    //         fast = fast->next->next;
    //         slow = slow->next;
    //         if(slow==fast){
    //           break;
    //         }
    //     }
    //     // if there are no loop in linked list return -1
    //     if(fast != slow)
    //       return -1;
        
    //     // if there is any loop 
    //     // declare a pointer pointing to start of linked list
    //     Node *st = head;
    //     //untill st pointer or loop spointer both not pointing to same node 
    //     while(st != slow){
    //         slow = slow->next;
    //         st = st->next;
    //     }
    //     // return data of first node of loop
    //     return st->data;
    }
};
