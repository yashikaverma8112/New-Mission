/*  https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1
class Node {
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
    Node* deleteNode(Node* head, int key) {
     
       if (!head) return NULL;    
        
        
       Node * curr = head;
       Node * prev = NULL;
        
        if(head->data == key){
            
            if(head->next==head){
                delete head;
                return NULL;
            }
            
            Node * last = head;
            while(last->next != head){
                last = last->next;
            }
            last->next = head->next;
            Node * temp = head;
            head = head->next;
            delete temp;
            return head;
        }
    
            
       curr = head->next;
       
       prev = head;
       
       while(curr != head){
           if(curr->data == key){
               prev->next = curr->next;
               curr->next = NULL;
               delete curr;
               return head;
           }
           
               prev = curr;
               curr = curr->next;
           
       }
      
       return head;
    }
};
