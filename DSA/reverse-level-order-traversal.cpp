//https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
class Solution {
  public:
  
    void reverse(vector<int>&ans){
        int s = 0;
        int e = ans.size()-1;
        
        while(s<=e){
            swap(ans[s],ans[e]);
            s++;
            e--;
        }
    }
  
    vector<int> reverseLevelOrder(Node *root) {
       vector<int>ans;
       
       queue<Node*>q;
       q.push(root);
       
       while(!q.empty()){
           Node * top = q.front();
           q.pop();
           ans.push_back(top->data);
           
           if(top->right){
               q.push(top->right);
           }
           if(top->left){
               q.push(top->left);
           }
       }
       
       reverse(ans);
       
       return ans;
    }
};
