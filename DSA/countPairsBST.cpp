/*  https://www.geeksforgeeks.org/problems/brothers-from-different-root/1
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    void findSum(Node*root1,Node*root2, int x, int &cnt){
        if(root1==NULL){
            return;
        }
        
        int sum = root2->data + root1->data;
        if(sum < x){
            findSum(root1->right,root2,x,cnt);
        }
        else if(sum > x){
            findSum(root1->left, root2, x, cnt);
        }
        else{
            cnt++;
            return;
        }
    }
  
    void inorder(Node*root1, Node*root2, int x, int&cnt){
        if(root2==NULL){
            return;
        }
        inorder(root1,root2->left,x,cnt);
        findSum(root1,root2,x,cnt);
        inorder(root1,root2->right,x,cnt);
    }
    
    int countPairs(Node* root1, Node* root2, int x) {
        
        int cnt = 0;
        inorder(root1,root2,x,cnt);
        return cnt;
}
};
