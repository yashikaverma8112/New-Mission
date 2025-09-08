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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
       if(root==NULL){
           return {};
       }
       vector<int>ans;
       
       map<int,int>mp;
           
       queue<pair<Node*,int>>q;
       q.push({root,0});
       
       while(!q.empty()){
           int n = q.size();
           
           for(int i=0; i<n;i++){
               
               auto top = q.front();
               q.pop();
               
               if(!mp.count(top.second)){
                   mp[top.second] = top.first->data;
               }
               if(top.first->left){
                   q.push({top.first->left, top.second-1});
               }
               if(top.first->right){
                   q.push({top.first->right, top.second+1});
               }
           }
       }
       
       for(auto i:mp){
           ans.push_back(i.second);
       }
       
       return ans;
    }
};
