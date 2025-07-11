class Solution {
  public:
  
    int solve(vector<int>& coins,int n, int sum){
        
        if(n == 0){
            return 0;
        }
        if(sum==0){
            return 1;
        }
        
        if(coins[n-1] > sum){
            return solve(coins,n-1,sum);
        }
        
        return solve(coins,n,sum-coins[n-1]) + solve(coins,n-1,sum);
    }
    
    int dp2D(vector<int>& coins,int n, int sum){
        vector<vector<int>>dp(n,vector<int>(sum+1));
        
        for(int i=0; i<sum+1; i++){
            if(i%coins[0]==0){
                dp[0][i] = 1;
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<sum+1; j++){
                int nottake = dp[i-1][j];
                
                int take =0;
                if(coins[i]<=j){
                    take = dp[i][j- coins[i]];
                }
                dp[i][j] = take + nottake;
            }
        }
        return dp[n-1][sum];
        }
    
    
    int count(vector<int>& coins, int sum) {
       int n = coins.size();
       
    //   return solve(coins,n,sum);
      return dp2D(coins,n,sum);
       
 
    }
};
