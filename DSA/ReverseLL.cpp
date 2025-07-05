Node* reverseList(struct Node* head) {
    
    if(head==NULL || head->next == NULL){
        return head;
    }

    Node * curr = head;
    Node * prev = NULL;

    while(curr!= NULL){
        Node * fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
        
}
