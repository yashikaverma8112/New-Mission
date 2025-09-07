/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
class Solution {
  public:
  
    Node * reverseLL(Node* head){
        if(head==NULL || head->next == NULL){
            return head;
        }
        
        Node * curr = head;
        Node * prev = NULL;
        Node * fwd = NULL;
        
        while(curr!= NULL){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            
        }
        return prev;
    }
  
    Node* addTwoLists(Node* head1, Node* head2) {
       
       head1 = reverseLL(head1);
       head2 = reverseLL(head2);
       
       Node * dummy = new Node(0);
       Node * curr = dummy;
       
       int carry = 0;
       
       while(head1 != NULL || head2 != NULL || carry > 0){
           int sum = carry;
           
           if(head1){
               sum += head1->data;
               head1 = head1->next;
           }
           if(head2){
               sum += head2->data;
               head2 = head2->next;
           }
           
           curr->next = new Node(sum%10);
           carry = sum/10;
           curr = curr->next;
       }
         Node * result = reverseLL(dummy->next);
         
         while(result && result->data==0 && result->next){
             result = result->next;
         }
         
         return result;
    }
};
