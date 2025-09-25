/*https://www.geeksforgeeks.org/problems/leaf-at-same-level/1
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    /*You are required to complete this method*/
    bool check(Node *root) {
        queue<Node*>q;
        q.push(root);
        int lvl = 0, leaf_level = -1;
        
        while(!q.empty()){
            int n = q.size();
            lvl++;
            
            for(int i=0; i<n;i++){
                Node *curr = q.front();
                q.pop();
                
                if(curr->left==NULL && curr->right == NULL){
                    if(leaf_level != -1 && leaf_level != lvl ){
                        return false;
                    }
                    leaf_level = lvl;
                }
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }    
            
        }
        return true;
    }
};
