// https://www.geeksforgeeks.org/problems/preorder-to-postorder4423/1

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    void solve(Node*&root, int v){
        if(root==NULL){
            root = newNode(v);
            return;
        }
        if(v < root->data){
            solve(root->left, v);
        }
        if(v > root->data){
            solve(root->right,v);
        }
        
    }
    
    Node* Bst(int pre[], int size) {
      Node * root = NULL;
      for(int i=0; i<size;i++){
         solve(root,pre[i]);
      }
      return root;    
    }
};
