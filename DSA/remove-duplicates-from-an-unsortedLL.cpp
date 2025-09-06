/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
class Solution {
  public:
    Node *removeDuplicates(Node *head) {
       
       if(head==NULL || head->next == NULL){
           return head;
       }
       unordered_set<int>hash;
       
       Node * curr = head;
       Node * prev = NULL;
       
       while(curr!=NULL){
           
           if(hash.count((curr->data))){
               prev->next = curr->next;
               delete curr;
               curr = prev->next;
           }
           else{
               hash.insert(curr->data);
               prev = curr;
               curr = curr->next;
           }
       }
       return head;
    }
};
