/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if(head == nullptr || k==1 || head->next==nullptr) {
        return head;
    }
    
    //step1: reverse first k nodes
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;
    
    while( curr != NULL && count < k ) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(curr != NULL) {
        head -> next = reverseKGroup(curr,k);
    }
    
    //step3: return head of reversed list
    return prev;
    }
    
};
