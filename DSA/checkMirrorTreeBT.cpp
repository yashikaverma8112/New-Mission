// https://www.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,stack<int>>mp;
        
        for(int i = 0; i<2*e; i+=2){
            mp[A[i]].push(A[i+1]);
        }
        
        for(int i=0; i<2*e; i+=2){
            if(mp[B[i]].top() != B[i+1]){
                return false;
            }
            mp[B[i]].pop();
        }
        return true;
    }
};
