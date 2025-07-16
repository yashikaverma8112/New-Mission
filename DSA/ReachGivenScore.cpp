
class Solution {
  public:
    // Complete this function
    
    // long long int solve(vector<int>&moves,long long int n,int i){
    //     if(n==0){
    //         return 1;
    //     }
    //     if(n<0 || i==moves.size()){
    //         return 0;
    //     }
        
    //     int incl = solve(moves,n-moves[i],i);
    //     int excl = solve(moves,n,i+1);
        
    //     return incl + excl;
    // }
    long long int solve(vector<int>&moves,long long int n,int i,vector<vector<int>>&dp){
        if(n==0){
            return 1;
        }
        if(n<0 || i==moves.size()){
            return 0;
        }
        
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        
        int incl = solve(moves,n-moves[i],i,dp);
        int excl = solve(moves,n,i+1,dp);
        
        return dp[i][n]=incl + excl;
    }
    
    
    
    long long int count(long long int n) {
       
       vector<int>moves={3,5,10};
       vector<vector<int>>dp(moves.size(),vector<int>(n+1,-1));
       return solve(moves,n,0,dp);
        
    }
};
