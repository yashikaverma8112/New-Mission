/*
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1
class Solution {
  public:
    int cycleStart(Node* head) {
        Node * slow = head;
        Node * fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast){
                slow = head;
                
                if(slow==fast){
                    // loop is at head
                   return fast->data;
                   
                }
                
                else{
                    while(slow->next != fast->next){
                        fast = fast->next;
                    }
                }
            }
        }
        return -1;
    }
};
