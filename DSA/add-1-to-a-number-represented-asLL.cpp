// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

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

class Solution {
  public:
  
    Node *reverseLL(Node * head){
        if(head==NULL || head->next == NULL){
            return head;
        }
        
        Node * prev = NULL;
        Node* curr= head;
        Node * fwd = NULL;
        
        while(curr != NULL){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        
        return prev;
    }
  
    Node* addOne(Node* head) {
      if(head==NULL){
          return head;
      }
      
      head = reverseLL(head);
      
      Node * curr = head;
      int carry = 1;
      
      while(curr!= NULL && carry > 0){
         int sum = curr->data + carry;
         
         curr->data = sum % 10;
         carry = sum / 10;
         
         if(curr->next==NULL && carry > 0){
             curr->next = new Node(carry);
             
             carry = 0;
         }
        curr = curr->next;
         
         
      }
      return reverseLL(head);
    }
};
