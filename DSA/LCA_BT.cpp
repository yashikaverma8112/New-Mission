/*  https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = right = NULL;
    }

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    Node* lca(Node* root, int n1, int n2) {
        if(root==NULL){
            return NULL;
        }
        if(root->data==n1 || root->data==n2){
            return root;
        }
        Node * leftAns = lca(root->left,n1,n2);
        Node * rightAns = lca(root->right,n1,n2);
        
        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }
        if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }
        else if(rightAns!=NULL && leftAns==NULL){
            return rightAns;
        }
        else{
            return NULL;
        }
        
    }
};
