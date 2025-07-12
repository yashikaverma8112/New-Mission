

class Solution {
  public:
    
    // int solve(vector<pair<int,int>>&arr, int target, int i,int ans){
    //     if(i==arr.size()) {
            
    //         if(target >=0){
    //             return ans;
    //         }
    //         return 0;
    //     }
        
    //     int incl = solve(arr,target-arr[i].second,i+1,ans+arr[i].first);
    //     int excl = solve(arr, target, i+1, ans);
        
    //     return max(incl , excl);
    // }
       int solve(vector<pair<int,int>>& arr, int target, int i, vector<vector<int>>& dp) {
        if (i == arr.size()) return 0;

        if (dp[i][target] != -1) return dp[i][target];

        int incl = 0;
        if (arr[i].second <= target) {
            incl = arr[i].first + solve(arr, target - arr[i].second, i + 1, dp);
        }

        int excl = solve(arr, target, i + 1, dp);

        return dp[i][target] = max(incl, excl);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({val[i], wt[i]});
        }

        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return solve(arr, W, 0, dp);
    }
};
