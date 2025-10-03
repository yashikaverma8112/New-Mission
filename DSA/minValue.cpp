// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    int minValue(Node* root) {
        
        int mini = INT_MAX;
        if(root==NULL){
            return mini;
        }
        mini = root->data;
        if(root->left){
            mini = min(mini, minValue(root->left));
        }
        
        return mini;
        
    }
};
