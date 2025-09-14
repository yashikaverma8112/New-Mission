/* https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
  public:
    
    struct Node *findPivot(struct Node *head){
        if(!head->next){
            return head;
        }
        int p = head->data;
        struct Node *j = head->next;
        struct Node *i = head;
        
        while(j){
            if(j->data < p){
                i = i->next;
                swap(i->data,j->data);
            }
            j = j->next;
        }
        
        swap(head->data, i->data);
        
        return i;
    }
  
    void sortQ(struct Node* head){
        if(!head){
            return;
        }
        struct Node *pivot = findPivot(head);
        struct Node *pre = NULL;
        struct Node *curr = head;
        
        while(curr != pivot){
            pre = curr;
            curr = curr->next;
        }
        
        if(pre){
            pre->next = NULL;
            sortQ(head);
            pre->next = pivot;
        }
        
        sortQ(pivot->next);
    }
  
    struct Node* quickSort(struct Node* head) {
        sortQ(head);
        return head;
    }
};
