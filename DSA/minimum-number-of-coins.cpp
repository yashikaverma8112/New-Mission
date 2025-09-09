// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

class Solution {
  public:
  
    int recursion(vector<int>&coins, int n){
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MAX;
        }
        
        int mini = INT_MAX;
        
        for(int i=0; i<coins.size();i++){
            int ans = recursion(coins,n-coins[i]);
            
            if(ans != INT_MAX)
                mini = min(mini,1+ans);
            
        }
        
        return mini;
    }
  
    int topDown(vector<int>&coins, int n , vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MAX;
        }
        
        int mini = INT_MAX;
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int i=0; i<coins.size();i++){
            int ans = topDown(coins,n-coins[i],dp);
            
            if(ans!=INT_MAX)
                mini = min(1+ans,mini);
        }
        
        dp[n] = mini;
        return dp[n];
    }
    
    int bottomUp(vector<int>&coins, int n){
        vector<int>dp(n+1,INT_MAX);
        dp[0] = 0;
        
        for(int i=1; i<=n;i++){
            for(int j=0; j<coins.size();j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(1+dp[i-coins[j]], dp[i]);
                }
            }
        }
        
        if(dp[n]==INT_MAX){
            return -1;
        }
        return dp[n];
    }
   
    
    int findMin(int n) {
        vector<int>coins;
        
        coins.push_back(1);
        coins.push_back(2);
        coins.push_back(5);
        coins.push_back(10);
        
        // int ans = recursion(coins,n);
        
        vector<int>dp(n+1,-1);
        int ans = topDown(coins,n,dp);
        if(ans==INT_MAX){
            return -1;
        }
        
        return bottomUp(coins,n);
    }
};
