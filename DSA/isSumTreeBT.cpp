// https://www.geeksforgeeks.org/problems/sum-tree/1

class Solution {
  public:
    // Helper that returns sum of subtree if it is Sum Tree, else -1
    int check(Node* root) {
        if (!root) return 0;

        // leaf node → return its value
        if (!root->left && !root->right) return root->data;

        int leftSum = check(root->left);
        int rightSum = check(root->right);

        // if any subtree is not Sum Tree
        if (leftSum == -1 || rightSum == -1) return -1;

        // check property
        if (root->data != leftSum + rightSum) return -1;

        // return total sum including this node
        return root->data + leftSum + rightSum;
    }

    bool isSumTree(Node* root) {
        return check(root) != -1;
    }
};
