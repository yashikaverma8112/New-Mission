/*  https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
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
  /*
    TC - O(nk)
    Node *merge(Node *head1, Node *head2){
        if(head1 && head2){
            if(head1->data < head2->data){
                head1->next = merge(head1->next, head2);
                return head1;
            }
            else{
                head2->next = merge(head1,head2->next);
                return head2;
            }
            
        }
        if(head1==NULL){
            return head2;
        }
        return head1;
    }
    
    Node* mergeKLists(vector<Node*>& arr) {
        Node *result = new Node(0);
        
        for(Node* val : arr){
            result = merge(result,val);
        }
        return result->next;
    }
    */
    // TC O(n log n)
    
    struct compare{
        bool operator()(Node*a, Node*b){
            return a->data > b->data;
        }
    };
    
    Node *solve(vector<Node*>& arr){
        priority_queue<Node*,vector<Node*>, compare>pq;
        
        for(Node *list : arr){
            if(list){
                pq.push(list);
            }
        }
        Node * result = new Node(-1);
        Node *dummy = result;
        while(!pq.empty()){
            Node *minNode = pq.top();
            pq.pop();
            
        
            if(minNode->next){
                pq.push(minNode->next);
            }
            dummy->next = minNode;
            dummy = dummy->next;
        }
        return result->next;
    }
    
     Node* mergeKLists(vector<Node*>& arr) {
       
       return solve(arr);
       
    }
};
