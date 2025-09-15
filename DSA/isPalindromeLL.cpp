/*  https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
  
    Node * findMid(Node*head){
        if(!head){
            return head;
        }
        Node *slow = head;
        Node * fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node *reverseLL(Node*head){
        if(!head || !head->next){
            return head;
        }
        Node *prev = NULL;
        Node *curr = head;
        
        while(curr!=NULL){
            Node * fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            
        }
        return prev;
    }
      
    bool compare(Node *head1, Node *head2){
        
        while(head1 && head2){
            if(head1->data!=head2->data){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
      
    bool isPalindrome(Node *head) {
        if(!head || !head->next){
            return true;
        }
        
        Node * mid = findMid(head);
        
        Node * reverse = reverseLL(mid->next);
        
        return compare(head,reverse);
    }
};
