/* https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
       
        int zero = 0, one = 0, two = 0;       
        
        Node *curr = head;
        
        while(curr!=NULL){
            if(curr->data==0){
                zero++;
            }
            else if(curr->data==1){
                one++;
            }
            else{
                two++;
            }
            
            curr = curr->next;
        }
        curr = head;
        
        while(zero){
            curr->data = 0;
            curr=curr->next;
            zero--;
        }
        while(one){
            curr->data = 1;
            curr=curr->next;
            one--;
        }
        while(two){
            curr->data = 2;
            curr=curr->next;
            two--;
        }
        return head;
    }
};
