/* https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            Node * top = q.front();
            q.pop();
            
            while(top){
                if(top->left){
                    q.push(top->left);
                }
                ans.push_back(top->data);
                top = top->right;
            }
        }
        return ans;
    }
};
