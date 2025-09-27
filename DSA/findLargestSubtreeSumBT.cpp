// https://www.geeksforgeeks.org/problems/largest-subtree-sum-in-a-tree/1

/*
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
*/

class Solution {
  public:
    // Function to find largest subtree sum.
    
    int solve(Node*root, int &maxSum){
        if(root == NULL){
            return 0;
        }
        int leftAns = solve(root->left, maxSum);
        int rightAns = solve(root->right, maxSum);
        
        maxSum = max(maxSum, leftAns + rightAns + root->data);
        
        return (leftAns + rightAns + root->data);
    }
    
    int findLargestSubtreeSum(Node* root) {
        int maxSum = INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};
