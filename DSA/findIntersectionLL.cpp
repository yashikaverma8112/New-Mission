/* https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/
class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // map<int,int>mp;
        
        // Node * curr = head1;
        
        // while(curr!=NULL){
        //     mp[curr->data]++;
        //     curr=curr->next;
        // }
        // curr = head2;
        // Node*ans = new Node(0);
        // Node * head=ans;
        // while(curr!=NULL){
        //     if(mp.count(curr->data)){
        //         Node*temp = new Node(curr->data);
        //         head->next = temp;
        //         head = head->next;
        //         mp[curr->data]--;
        //     }
        //     curr=curr->next;
        // }
        // return ans->next;
        
        Node *ans = new Node(0);
        Node *head=ans;
        
        while(head1 && head2){
            if(head1->data > head2->data){
                head2=head2->next;
            }
            else if(head1->data < head2->data){
                head1 = head1->next;
            }
            else{
                head->next = head1;
                head1 = head1->next;
                head2 = head2->next;
                head = head->next;
                head->next = NULL;
            }
        }
        return ans->next;
    }
};
