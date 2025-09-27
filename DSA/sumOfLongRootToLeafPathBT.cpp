/*  https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int maxLen = 0;
    int maxSum = 0;
    
    void dfs(Node *root, int len, int sum){
        if(root==NULL){
            return;
        }
        len++;
        
        sum = sum + root->data;
        
        if(root->left == NULL && root->right == NULL){
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len==maxLen){
                maxSum = max(maxSum,sum);
            }
            return;
        }
        dfs(root->left,len,sum);
        dfs(root->right,len,sum);
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
       
        dfs(root,0,0);
        return maxSum;
    }
};
