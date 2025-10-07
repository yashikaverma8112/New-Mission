/* https://www.geeksforgeeks.org/problems/binary-tree-to-bst/1
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    void preorder(Node*root, priority_queue<int>&pq){
        if(root==NULL){
            return;
        }
        pq.push(root->data);
        preorder(root->left,pq);
        preorder(root->right, pq);
    }
    
    void inorder(Node *root, priority_queue<int>&pq){
        if(root==NULL){
            return;
        }
        inorder(root->right,pq);
        root->data = pq.top();
        pq.pop();
        inorder(root->left,pq);
    }
    
    Node *binaryTreeToBST(Node *root) {
       priority_queue<int>pq;
       preorder(root,pq);
       
       inorder(root,pq);
       
       return root;
    }
};
