//https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        
        int low = mat[0][0];
        int high = mat[n-1][n-1];
        
        while(low < high){
            int mid = low + (high - low)/2;
            
            int row = n-1;
            int col = 0;
            int cnt = 0;
            
            while(row >=0 && col < n){
                if(mat[row][col] <= mid){
                    cnt += row + 1;
                    col++;
                }
                else{
                    row--;
                }
            }
            
            if(cnt < k){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};
