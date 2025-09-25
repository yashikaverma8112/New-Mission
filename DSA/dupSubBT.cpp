/*https://www.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    
    map<string,int>hash;
    
    
    string solve(Node *root){
        if(root==NULL){
            return "*";
        }
        string str = "";
        
        if(root->left == NULL && root->right == NULL){
            str += to_string(root->data);
            return str;
        }
        str += to_string(root->data);
        str += '/';
        str += solve(root->left);
        str += ',';
        str += solve(root->right);
        hash[str]++;
        return str;
    }
    
    int dupSub(Node *root) {
        solve(root);
        
        for(auto it : hash){
            if(it.second > 1){
                return 1;
            }
        }
        return 0;
    }
};
