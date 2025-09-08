/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    vector<int> rightView(Node *root) {
        if(root==NULL){
            return {};
        }
        
        vector<int>ans;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0; i<n;i++){
                Node * top = q.front();
                q.pop();
                
                if(i==n-1){
                    ans.push_back(top->data);
                }
                
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
        
        return ans;
    }
};
