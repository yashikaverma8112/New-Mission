// https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
        /*
        Node *oddHead = new Node(-1);
        Node *evenHead = new Node(-1);
        
        Node *odd = oddHead;
        Node *even = evenHead;
        
        Node *curr = head;
        
        while(curr){
            if(curr->data % 2){
                odd->next = curr;
                odd = odd->next;
            }
            else{
                even->next = curr;
                even = even->next;
            }
            curr = curr->next;
        }
        odd->next = NULL;
        even->next = oddHead->next;
        return evenHead->next;
        */
        if (!head || !head->next) return head;
        
        Node *oddHead = NULL;
        Node *oddTail = NULL;
        
        Node *evenHead = NULL;
        Node *evenTail = NULL;
        
        Node *curr = head;
        
        while(curr){
            if(curr->data % 2==0){
                if(!evenHead){      // first node
                    evenHead = curr;
                    evenTail = curr;
                }
                else{
                    evenTail->next = curr;
                    evenTail = evenTail->next;
                }
            }
            else{
                if(!oddHead){       //first node
                    oddHead = curr;
                    oddTail = curr;
                }
                else{
                    oddTail->next = curr;
                    oddTail = oddTail->next;
                }
            }
            curr = curr->next;
        }
        
        if(!evenHead){
            return oddHead;
        }
        if(!oddHead){
            evenTail->next = NULL;
            return evenHead;
        }
        evenTail->next = oddHead;
        
        if(oddTail){
            oddTail->next = NULL;
        }
        
        return evenHead;
    }
};
