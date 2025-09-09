// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    
    int recur(vector<int>& arr, int n){
        if(n==0){
            return arr[0];
        }
        if(n<0){
            return 0;
        }
        int incl = recur(arr,n-2) + arr[n];
        int excl = recur(arr,n-1) + 0;
        
        return max(incl,excl);
    }
    
    int topdwn(vector<int>&arr,int n, vector<int>&dp){
        if(n==0){
            return arr[0];
        }
        if(n<0){
            return 0;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int incl = topdwn(arr,n-2,dp) + arr[n];
        int excl = topdwn(arr,n-1,dp) + 0;
        
        dp[n] = max(incl,excl);
        
        return dp[n];
    }
    
    int bottomUp(vector<int>&arr, int n){
        vector<int>dp(n+1,0);
        dp[0] = arr[0];
        dp[1] = max(arr[0],arr[1]);
        
        for(int i=2; i<n; i++){
            int incl = dp[i-2] + arr[i];
            int excl = dp[i-1] + 0;
            dp[i] = max(incl,excl);
        }
        
        return dp[n-1];
    }
    
    int spaceOpt(vector<int>&arr, int n){
        int prev2 = arr[0];
        int prev1 = max(arr[0],arr[1]);
        
        for(int i=2; i<n; i++){
            int incl = prev2 + arr[i];
            int excl = prev1 + 0;
            
            int curr = max(incl,excl);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        // int ans = recur(arr,n-1);
        vector<int>dp(n+1,-1);
        // int ans = topdwn(arr,n-1,dp);
        
        return spaceOpt(arr,n);
    }
};
