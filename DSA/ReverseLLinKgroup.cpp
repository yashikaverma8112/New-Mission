/*
class Node {
  public:
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
   
    Node *reverseKGroup(Node *head, int k) {
        if(head==NULL or head->next == NULL){
            return head;
        }
        Node * prev = NULL;
        Node * curr = head;
        Node * fwd = NULL;
        int cnt = 0;
        
        while(curr != NULL && cnt < k){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            cnt++;
        }
        
        if(fwd != NULL){
            head->next = reverseKGroup(fwd,k);
        }
        return prev;
    }
};
