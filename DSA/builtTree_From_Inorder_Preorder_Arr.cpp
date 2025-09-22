// https://www.geeksforgeeks.org/problems/construct-tree-1/1
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    
    Node *helper(vector<int> &inorder, vector<int> &preorder, int inStart, int inEnd
    , int &preIndex, unordered_map<int,int>&inMp){
        if(inStart > inEnd){
            return NULL;
        }
        
        int rootVal = preorder[preIndex++];
        Node *root = new Node(rootVal);
        
        int rootInd = inMp[rootVal];
        
        root->left = helper(inorder,preorder, inStart,rootInd-1, preIndex, inMp);
        root->right = helper(inorder,preorder, rootInd+1,inEnd, preIndex, inMp);
        
        return root;
        
    }
    
  
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int preIndex = 0;
        
        unordered_map<int,int>inMp;
        
        for(int i=0; i<n; i++){
            inMp[inorder[i]] = i;
        }
        
        return helper(inorder, preorder,0,n-1,preIndex, inMp);
    
    }
};
