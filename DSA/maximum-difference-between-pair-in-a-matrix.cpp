//https://www.geeksforgeeks.org/problems/maximum-difference-between-pair-in-a-matrix/1

class Solution {
  public:
    int findMaxValue(vector<vector<int>>& mat, int N) {
        // TC - O(n square) 
        int maxi = INT_MIN;
        
       nt i=N-1; i>=0; i--){
             for(ifor(int j = N-1; j>=0; j--){
                if(i+1 < N && j+1 < N){
                    maxi = max(maxi, mat[i+1][j+1]-mat[i][j]);
                }
                if(i+1 < N) mat[i][j] = max(mat[i][j], mat[i+1][j]);
                if(j+1 < N) mat[i][j] = max(mat[i][j], mat[i][j+1]);
            }
        }
        
        return maxi;
    }
};
