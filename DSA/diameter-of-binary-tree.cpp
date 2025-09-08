/* https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
  
    int solve(Node * root , int &res){
        if(root==NULL){
            return 0 ;
        }
        
        int leftDia = solve(root->left,res);
        int rightDia = solve(root->right,res);
        
        res = max(res, leftDia + rightDia);
        
        return max(leftDia,rightDia) +1;
    }
  
    int diameter(Node* root) {
        int res = 0;
        
        solve(root,res);
        return res;
    }
};
