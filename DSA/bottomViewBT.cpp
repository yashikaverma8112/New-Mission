/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        if(root==NULL){
            return {};
        }
        
        vector<int>ans;
        map<int,int>mp;
        
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            mp[front.second] = front.first->data;
            
            if(front.first->left){
                q.push({front.first->left,front.second-1});
            }
            if(front.first->right){
                q.push({front.first->right,front.second+1});
            }
            
        }
        
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
