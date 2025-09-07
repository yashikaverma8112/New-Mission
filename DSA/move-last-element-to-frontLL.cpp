// https://www.geeksforgeeks.org/problems/move-last-element-to-front-of-a-linked-list/1

class Solution {
  public:
    Node *moveToFront(Node *head) {
       if(head==NULL || head->next==NULL){
           return head;
       }
       
       Node * curr = head;
       Node * prev = NULL;
       while(curr->next !=NULL){
           prev = curr;
           curr = curr->next;
       }
       prev->next = NULL;
       curr->next= head;
       head = curr;
       
       return head;
    }
};
