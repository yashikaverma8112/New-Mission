/* https://www.geeksforgeeks.org/problems/largest-bst/1
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    class info{
        public :
        
            int maxi;
            int mini;
            bool isBst;
            int size;
    };
    
    info solve(Node*root, int &ans){
        if(root==NULL){
            return {INT_MIN, INT_MAX, true,0};
        }
        
        info left = solve(root->left,ans);
        info right = solve(root->right,ans);
        
        info curr ;
        
        curr.size = left.size + right.size + 1;
        curr.maxi = max(root->data, right.maxi);
        curr.mini = min(root->data, left.mini);
       
        if(left.isBst && right.isBst && (root->data > left.maxi && root->data < right.mini))
        {
            curr.isBst = true;
            ans = max(ans,curr.size);
        }
        else{
            curr.isBst = false;
        }
        
        return curr;
    }
    
    int largestBst(Node *root) {
        // Your code here
        int maxSize = 0;
        
        info temp = solve(root,maxSize);
        
        return maxSize;
    }
};
