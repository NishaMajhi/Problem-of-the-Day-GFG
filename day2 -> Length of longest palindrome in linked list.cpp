/*
Given a linked list, the task is to complete the function maxPalindrome() which returns an integer denoting 
the length of the longest palindrome list that exist in the given linked list.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. The first line of each test case contains an integer N denoting the size of the linked list .
Then in the next line are N space separated values of the given linked list.


Output:
For each test case output will be the required max length of the palindrome present in the given linked list.


User Task:
The task is to complete the function maxPalindrome() which should count the length of longest palindrome in the given list and return it.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
7
2 3 7 3 2 12 24
5
12 4 4 3 14

Output:
5
2

Explanation:
Testcase 1: 2 -> 3 -> 7 -> 3 -> 2 is the linked list whose nodes leads to a palindrome as 2 3 7 3 2.
*/




/* The Node is defined 
  /* Link list Node
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

/*The function below returns an int denoting
the length of the longest palindrome list. */
int maxPalindrome(Node *head)
{
    Node *prev = NULL;
    Node *cur = head;
    int ans = 0;
    while( cur ){
        Node *next = cur->next;
        int curans = 1;
        Node *p = prev;
        Node *n = next;
        while( p and n ){
            if( p->data == n->data ) curans += 2;
            else {
                break;
            }
            p = p->next; n = n->next;
        }
        
        ans = max(ans, curans );
        curans = 0;
        
        p = cur; n = prev;
        while( p and n ){
            if( p->data == n->data ) curans+= 2;
            else{
                break;
            }
            p = p->next; n = n->next;
        }
        
        ans = max(ans, curans );
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    return ans;
}
