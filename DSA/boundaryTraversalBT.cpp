/*https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
     void leftTraversal(Node *root, vector<int>&ans){
         if(root==NULL){
             return;
         }
         if(root->left==NULL && root->right==NULL){
             return;
         }
         ans.push_back(root->data);
         if(root->left){
             leftTraversal(root->left,ans);
         }
         else{
             leftTraversal(root->right,ans);
         }
         
     }
     void leafTraversal(Node *root, vector<int>&ans){
         if(root==NULL){
             return;
         }
         if(root->left==NULL && root->right==NULL){
             ans.push_back(root->data);
             return;
         }
         leafTraversal(root->left,ans);
         leafTraversal(root->right,ans);
     }
     void rightTraversal(Node *root, vector<int>&ans){
         if(root==NULL || (root->left==NULL && root->right==NULL) ){
             return;
         }
         if(root->right){
             rightTraversal(root->right,ans);
         }
         else{
             rightTraversal(root->left,ans);
             
         }
         ans.push_back(root->data);
     }
  
    vector<int> boundaryTraversal(Node *root) {
       vector<int>ans;
       if(root==NULL){
           return ans;
       }
       
       ans.push_back(root->data);    
        
      if(root->left==NULL && root->right==NULL){
          return ans;
      }        
        
      if(root->left){
          leftTraversal(root->left,ans);
      } 
      leafTraversal(root,ans);
      if(root->right){
          rightTraversal(root->right,ans);
      }
      return ans;
    }
};
