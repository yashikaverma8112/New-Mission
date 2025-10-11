/*
// Tree Node
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
    int cnt = 0;
    int getCount(Node *root, int l, int h) {
        
        if(root==NULL){
            return 0;
        }
        
        if(root->data <= h && root->data >= l ){
            cnt++;
        }
        getCount(root->left,l,h);
        getCount(root->right,l,h);
        
        return cnt;
    }
};
