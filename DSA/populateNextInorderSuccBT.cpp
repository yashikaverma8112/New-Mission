/* https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
  
    void inorder(Node*root, vector<Node*>&v){
        if(root==NULL) return;
        
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    
    void populateNext(Node *root) {
        if(root==NULL){
            return;
        }
        vector<Node*>v;
        inorder(root,v);
        
        for(int i=0; i<v.size()-1; i++){
            v[i]->next =  v[i+1];
        }
        
    }
};
