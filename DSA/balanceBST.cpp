/*Structure of the Node of the BST is as
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {

  public:
    
    Node *buildBST(vector<int>&inorder, int start , int end){
        if(start > end){
            return NULL;
        }
        int mid = (start + end)/2;
        
        Node * root = new Node(inorder[mid]);
        
        root->left = buildBST(inorder,start,mid-1);
        root->right = buildBST(inorder,mid+1,end);
        
        return root;
    }
    
    void getInorder(Node *root, vector<int>&inorder){
        if(root==NULL){
            return;
        }
        
        getInorder(root->left, inorder);
        inorder.push_back(root->data);
        getInorder(root->right, inorder);
    }
  
    Node* balanceBST(Node* root) {
        vector<int>inorder;
        getInorder(root,inorder);
        
        return buildBST(inorder,0,inorder.size()-1);
        
    }
};
