// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        vector<int>preSum(n);
        vector<int>postSum(n);
        
        preSum[0] = arr[0];
        postSum[n-1] = arr[n-1];
        
        for(int i=1; i<n; i++){
            preSum[i] = max(preSum[i-1],arr[i]);
        }
        for(int i = n-2; i>=0; i--){
            postSum[i] = max(postSum[i+1],arr[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            
            if(preSum[i] > arr[i] && postSum[i] > arr[i]){
                
                ans += min(preSum[i],postSum[i]) - arr[i];
            }
        }
        
        return ans;
    }
};
