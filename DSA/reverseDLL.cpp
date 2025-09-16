/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
       if(!head || !head->next){
           return head;
       }
       
       Node *curr = head;
       Node * fwd = NULL;
       while(curr!=NULL){
           fwd = curr->prev;
           curr->prev = curr->next;
           curr->next = fwd;
           curr = curr->prev;
       }
       
       if(fwd!=NULL){
           head = fwd->prev;
       }
       
       return head;
    }
};
