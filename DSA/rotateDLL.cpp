/*  https://www.geeksforgeeks.org/problems/rotate-doubly-linked-list-by-p-nodes/1
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *rotateDLL(Node *head, int p) {
        
        if(!head || !head->next){
            return head;
        }
        
        Node * curr = head->next;
        
        Node *tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        
        while(p>0){
            
            head->next = NULL;
            head->prev = tail;
            tail->next = head;
            tail = head;
            curr->prev = NULL;
            head = curr;
            curr = curr->next;
            p--;
        }
        return head;
    }
};
