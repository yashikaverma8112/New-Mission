/* 
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    
    struct Node * findMid(struct Node* head){
        if(!head){
            return head;
        }
        
        struct Node * slow = head;
        struct Node * fast = head;
        
        while(fast->next != head && fast->next->next !=head){
            slow = slow->next;
            fast = fast->next->next;
           
        }
        return slow;
        
    }
  
    pair<Node *, Node *> splitList(struct Node *head) {
        
        if(!head || !head->next){
            return {head,head};
        }
        
        Node * mid = findMid(head);
        Node * nextOfMid = mid->next;
        
        Node * curr = head;
        while(curr != mid){
            curr = curr->next;
        }
        curr->next = head;
        Node * nextHalf = nextOfMid;
        while(nextHalf->next != head){
            nextHalf = nextHalf->next;
        } 
        nextHalf->next = nextOfMid;
        
        return {head,nextOfMid};
    }
};
