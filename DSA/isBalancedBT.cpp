/*https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

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
    
    int HeightDiff(Node *root){
        if(root==NULL){
            return 0;
        }
        
        int leftHeight = HeightDiff(root->left);
        if(leftHeight==-1){
            return -1;
        }
        
        int rightHeight = HeightDiff(root->right);
        if(rightHeight==-1){
            return -1;
        }
        
        if(abs(rightHeight-leftHeight) > 1){
            return -1;
        }
        
        return 1+max(leftHeight, rightHeight);
    }
  
    bool isBalanced(Node* root) {
       return HeightDiff(root) != -1;
    }
};
