/*  https://www.geeksforgeeks.org/problems/sort-a-linked-list/1
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
    
    Node *merge (Node*left, Node*right){
        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        Node * result = NULL;
        if(left->data <= right->data){
            result = left;
            result->next = merge(left->next,right);
        }
        else{
            result = right;
            result->next = merge(left,right->next);
        }
        return result;
    }
    
    Node * findMid(Node * head){
        
        if(!head){
            return head;
        }
        
        Node * slow = head;
        Node * fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
  
    Node* mergeSort(Node* head) {
    
    
        if(head==NULL || head->next==NULL){
            return head;
        }    
        
       Node * mid = findMid(head);
       Node * nextOfMid = mid->next;
       mid->next = NULL;
       
       Node * left = mergeSort(head);
       Node * right = mergeSort(nextOfMid);
       
       return merge(left,right);
       
    }
};
