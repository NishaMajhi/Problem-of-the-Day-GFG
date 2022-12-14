/*
Sort the given doubly linked list of size N using quicksort. Just complete the partition function using the quicksort technique.
 
Example 1:
Input:
LinkedList: 4->2->9

Output:
2 4 9

Explaination: After sorting output will look like this.



Example 2:
Input:
LinkedList: 1->4->9->2

Output:
1 2 4 9

Explaination: After sorting output will look like this.


Your Task:
Your task is to complete the given function partition(),
which accepts the first and last node of the given linked list as input parameters and returns the pivot's address.
 

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)
 

Constraints:
1 <= N <= 2000
1 <= Each Element of Double Linked List <= 105
*/


#include <bits/stdc++.h>
using namespace std;
 
/* a Node of the doubly linked list */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct Node *lastNode(Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}


class Solution{
public:

    void swap(int &a ,int &b){
       int t = a;
       a = b;
       b = t;
    }

    Node* partition(Node *l, Node *h){
       
       int d = h->data;
       Node *i = l->prev;
       
       for(Node *j = l; j != h; j = j->next){
           if(j->data <= d){
                i = (i == NULL ) ? l : i->next;
               swap(i->data,j->data);
           }
       }
       i = (i == NULL ) ? l : i->next;
       swap(i->data,h->data);
       return i;
       
    
    }
};


void _quickSort(struct Node* l, struct Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        Solution ob;
        struct Node *p = ob.partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
 
void quickSort(struct Node *head)
{
    // Find last Node
    struct Node *h = lastNode(head);
 
    // Call the recursive QuickSort
    _quickSort(head, h);
}

// A utility function to print contents of arr
void printList(struct Node *head)
{
    while (head)
    {
        cout << head->data << "  ";
        head = head->next;
    }
    cout << endl;
}

 
int main()
{
    int t,x,n,i;
    scanf("%d",&t);
    while(t--)
    {
        /* Start with the empty list */
        struct Node *p,*temp,*head = NULL;
        scanf("%d",&n);
        scanf("%d",&x);
        head=new Node(x);
        p=head;
        for(i=0;i<n-1;i++){
            scanf("%d",&x);
            /* Let us create the doubly linked list 10<->8<->4<->2 */
        	temp=new Node(x);
        	p->next=temp;
        	temp->prev=p;
            p=p->next;
        }
    
    //printList(head); 
    /* delete Nodes from the doubly linked list */
	
    quickSort(head);
  
    /* Modified linked list will be NULL<-8->NULL */
    printList(head);           
    while(head->next!=NULL)
    {
	  temp=head;
	  head=head->next;
	  free(temp);
	}
	  free(head);
	}
    return 0;
}
