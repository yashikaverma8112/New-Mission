class Solution {
  public:
        int maxGold(vector<vector<int>>& mat) {
        // code here
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> prev (rows, 0);
        int ans = 0;
        for(int i = 0; i < rows; i++){
            prev[i] = mat[i][0];
            ans = max(prev[i], ans);
        }
        vector<int> curr (rows, 0);
        for(int j =  1; j < cols; j++){
            for(int i = 0; i < rows; i++){
                int currGold = mat[i][j];
                if(i - 1 >= 0 && currGold < prev[i - 1] + mat[i][j]){
                    currGold = prev[i - 1] + mat[i][j];
                }
                if(i + 1 < rows && currGold < prev[i + 1] + mat[i][j]){
                    currGold = prev[i + 1] + mat[i][j];
                }
                if(currGold < prev[i] + mat[i][j]){
                    currGold = prev[i] + mat[i][j];
                }
                curr[i] = currGold;
                ans = max(currGold, ans);
            }
            prev = curr;
        }
        return ans;
    }
};
