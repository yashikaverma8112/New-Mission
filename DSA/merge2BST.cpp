/*    https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
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
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    void inorder(Node*root, vector<int>&t){
        if(root==NULL){
            return ;
        }
        
        t.push_back(root->data);
        inorder(root->left,t);
        inorder(root->right,t);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        vector<int>t1,t2;
        
        inorder(root1,t1);
        inorder(root2,t2);
        
        vector<int>ans(t2);
        
        for(int i=0; i<t1.size(); i++){
            ans.push_back(t1[i]);
        }
    
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
