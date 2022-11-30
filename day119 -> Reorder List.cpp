/*
Given a singly linked list: A0→A1→...→An-2→An-1, reorder it to: A0→An-1→A1→An-2→A2→An-3→...
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

Note: It is recommended do this in-place without altering the node's values.


Example 1:

Input:
LinkedList: 1->2->3
Output: 1 3 2
Explanation:
Here n=3, so the correct
order is A0→A2→A1


Example 2:

Input:
Explanation: 1->7->3->4
Output: 1 4 7 3
Explanation:
Here n=4, so the correct
order is A0→A3→A1→A2


Your Task:
The task is to complete the function reorderList() which should reorder the list as required. 
The reorder list is automatically printed by the driver's code.

Note: Try to solve without using any auxilliary space.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 5*105
1 <= A[ i ] <= 105
*/



/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    void reorderList(Node* head) {
      
        //with extra space of O(N)
        Node *curr = head;
        
        deque<int> dq;
        while(curr != NULL){
            dq.push_back(curr->data);
            curr = curr->next;
        }
        
        curr = head;
        int n = dq.size();
        int f = 1;
        
        while(curr != NULL && n){
            if(f==1){
                curr->data = dq.front();
                dq.pop_front();
            }
            else{
                curr->data = dq.back();
                dq.pop_back();
            }
            
            f = (f==1)?0:1;
            curr = curr->next;
        }
      
      
      /*
      //inplace reorder without using extra space
      
       Node* reverse(Node *head){
        Node *curr = head,*prev = NULL,*next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
      }

    void reorderList(Node* head) {
       
       //step 1 -> find mid element of Linked List
       Node *fast = head->next;
       Node *slow = head;
       while(fast != NULL && fast->next != NULL){
           slow = slow->next;
           fast = fast->next->next;
       }
       
       //step 2 -> find L1 = head and L2 = reverse after mid element
       Node *firstLL = head;
       Node *secondLL = reverse(slow->next);
       slow->next = NULL;
       
       
       //step 3 -> merge both halves
       Node *ans = new Node(1);
       Node *curr = ans;
       
       while(firstLL || secondLL){
         if(firstLL){
            curr->next = firstLL;
            firstLL = firstLL->next;
            curr = curr->next;
         }
         if(secondLL){
             curr->next = secondLL;
             curr = curr->next;
             secondLL = secondLL->next;
         }
       }
       
       head = ans->next;
      
      */
      
      
    }
};
