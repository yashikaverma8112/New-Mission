/*  https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        
        if(!head)
            return NULL;
            
       // step 1 : Insert clone nodes in between
         
         Node * curr = head;
         
         while(curr != NULL){
             Node * copy = new Node(curr->data);
             copy->next = curr->next;
             curr->next = copy;
             curr = copy->next;
         }
         
       
       // step 2 : Copy random pointers from original node to clone node
            
         curr = head;
         
         while(curr){
             
             if(curr->random )
                 curr->next->random = curr->random->next;
            
            curr = curr->next->next;
         }
            
        
       // step 3 : detach the clone LL
         Node * dummy = new Node(0);
         Node *copycurr = dummy;
         curr = head;
         
         while(curr){
             Node *copy = curr->next;
             curr->next = copy->next;
             copycurr->next = copy;
             copycurr = copy;
             curr = curr->next;
         }
         return dummy->next;
    }
};
