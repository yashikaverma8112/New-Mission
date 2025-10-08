/*https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

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
    int kthSmallest(Node *root, int k) {
        vector<int>inorder;
        inOrder(root, inorder);
        
        if(inorder.size() < k){
            return -1;
        }
        
        return inorder[k-1];
    }
};
