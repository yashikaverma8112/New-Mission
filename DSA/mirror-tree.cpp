/*  https://www.geeksforgeeks.org/problems/mirror-tree/1
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* node) {
        if(node==NULL){
            return ;
        }
        
        Node * temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        if(node->left){
            mirror(node->left);
        }
        if(node->right){
            mirror(node->right);
        }
    }
};
