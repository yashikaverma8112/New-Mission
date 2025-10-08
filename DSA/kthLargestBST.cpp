/*https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
  
    void inOrder(Node *root,vector<int>&in ){
        if(root==NULL){
            return;
        }
        inOrder(root->left,in);
        in.push_back(root->data);
        inOrder(root->right,in);
    }
    
    int kthLargest(Node *root, int k) {
        vector<int>inorder;
        inOrder(root, inorder);
        
        return inorder[inorder.size()-k];
    }
};
