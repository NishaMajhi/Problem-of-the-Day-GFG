/*

Given a linked list of characters and a string S.Return all the anagrams of the string present in the given linked list.
In case of overlapping anagrams choose the first anagram from left.



Example 1:
Input: a -> b -> c -> a -> d -> b -> c -> a
S = bac
Output: [a -> b -> c, b -> c -> a]
Explanation: In the given linked list,
there are three anagrams: 
1. a -> b -> c -> a -> d -> b -> c -> a
2. a -> b -> c -> a -> d -> b -> c -> a
3. a -> b -> c -> a -> d -> b -> c -> a
But in 1 and 2, a -> b -> c and b -> c-> a
are ovelapping.So we take a -> b -> c as it
comes first from left.So the output is:
[a->b->c,b->c->a]



Example 2:
Input: a -> b -> d -> c -> a
S = bac
Output: -1 
Explanation: There is no anagrams, so output is -1


Your Task:
You don't need to read input or print anything. Your task is to complete the function findAnagrams() which takes head node of the linked list 
and a string S as input parameters and returns an array of linked list which only stores starting point of the Anagram. 
If there is no anagram in the linked list,return -1.


Expected Time Complexity: O(N), where N is length of LinkedList
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 105
1 <= |S| <= 105
*/



/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        unordered_map<char,int>mp;
        unordered_map<char,int>linkMap;
        for(auto i:s)mp[i]++;
        int i=0;
        int n=s.size();
        Node*slow=head;
        vector<Node*>res;
        Node*fast=head;
        while(fast!=nullptr){
            char data=fast->data;
            if(mp.find(data)==mp.end()){
                fast=fast->next;
                slow=fast;
                linkMap.clear();
                i=0;
            }
            else{
                if(linkMap[data]<mp[data]){
                    linkMap[data]++;
                    i++;
                    if(i==n){
                    Node*tep=fast->next;
                    fast->next=nullptr;
                    res.push_back(slow);
                    fast=tep;
                    slow=fast;
                    linkMap.clear();
                    i=0;
                    continue;
                }
                }else{
                    while(slow->data!=data){
                        i--;
                        linkMap[slow->data]--;
                        slow=slow->next;
                    }
                    i--;
                    linkMap[slow->data]--;
                    slow=slow->next;
                    continue;
                
                }
                fast=fast->next;
                
            }
        }
        return res;
    }
};
