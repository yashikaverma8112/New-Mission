/*
https://www.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    
    Node *reverse(Node*head){
        
        if(!head || !head->next){
            return head;
        }
        
        Node * pre = NULL;
        Node *curr = head;
        
        while(curr){
            Node *fwd = curr->next;
            curr->next = pre;
            pre = curr;
            curr = fwd;
            
        }
        return pre;
    }
    
    
    
    Node *compute(Node *head) {
      head = reverse(head);
      
      Node * curr = head->next;
      Node *prev = head;
      int maxi = head->data;
      
      while(curr){
          if(curr->data >= maxi){
              maxi = curr->data;
              prev = curr;
          }
          else{
             prev->next = curr->next;
             curr->next=NULL;
             delete curr;
            
          }
          curr = prev->next;
      }
      return reverse(head);
      
    }
};
