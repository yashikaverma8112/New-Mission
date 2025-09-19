/*
https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        Node*slow = head;
        Node*fast = head;
        
        for(int i=1;i<=k; i++){
            if(fast==NULL){
                return -1;
            }
            fast = fast->next;
        }
        
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
};
