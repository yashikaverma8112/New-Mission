/* https://www.geeksforgeeks.org/problems/predecessor-and-successor/1
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  
    Node * solvePre(Node *root, int key){
        if(root==NULL){
            return NULL;
        }
        Node * ans = root;
        if(root->right){
           ans = solvePre(root->right,key);
         
        }
        
        return ans;
    }
  
    Node * solveSucc(Node *root, int key){
        if(root==NULL){
            return NULL;
        }
        Node * ans = root;
        if(root->left){
           ans = solveSucc(root->left,key);
        }
        
        return ans;
    }
  
   
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*>ans;
      
        
        Node * predecessor = NULL ;
        Node * successor = NULL;
        Node * curr = root;
        
        
        while(curr){
            if(curr->data < key){
                predecessor = curr;
                curr = curr->right;
            }
            else if(curr->data > key){
                successor = curr;
                curr = curr->left;
            }
            else{
                
                if(curr->left){
                    predecessor =solvePre(curr->left, key);
                }
                if(curr->right){
                    successor = solveSucc(curr->right,key);
                }
                break;
            }
        }
        
        ans.push_back(predecessor);
        ans.push_back(successor);
        
        return ans;
    }
};
