//https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        /* TC O(n*m)
        int n = arr.size();
        int m = arr[0].size();
        int ans = -1;
        int res = -1;
        for(int i=0; i<n; i++){
            int ones = 0;
            for(int j=m-1; j>=0; j--){
                if(arr[i][j]==0){
                    break;
                }
                else{
                    ones++;
                }
            }
            if(ans < ones){
                ans = max(ans,ones);
                res = i;
            }
        }
        return res;
        */
        
        
        // TC - O(n+m)
        
        int n = arr.size();
        int m = arr[0].size();
        int res = -1;    
        int j = m-1;
        for(int i=0; i<n; i++){
            while(j>=0 && arr[i][j]==1){
                res = i;
                j--;
            }
        }
        return res;
    }
};
