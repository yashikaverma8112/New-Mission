/*  https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
       vector<int>result;
       
       queue<Node*>q;
       q.push(root);
       
       bool leftToRight = true;
       
       while(!q.empty()){
            int sz = q.size();
            vector<int>level;
            
            for(int i=0; i<sz; i++){
                Node *top = q.front();
                level.push_back(top->data);
                q.pop();
                
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            
            if(!leftToRight)
            {
                reverse(level.begin(),level.end());
            }
            
            for(int val : level){
                result.push_back(val);
            }
            leftToRight = !leftToRight;
       }
       return result;
    }
};
