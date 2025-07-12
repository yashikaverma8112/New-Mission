class Solution {
  public:
  
   bool solve(int index,vector<int>&arr,int target,vector<vector<int>>&dp){
      if(index>=arr.size()){
          return 0;
      }
      if(target<0){
          return 0;
      }
      if(target==0){
          return 1;
      }
      if(dp[index][target]!=-1){
          return dp[index][target];
      }
      bool include=solve(index+1,arr,target-arr[index],dp);
      bool exclude=solve(index+1,arr,target,dp);
      return dp[index][target]=include or exclude;
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum & 1){
            return 0;
        }
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        bool ans=solve(0,arr,target,dp);
        return ans;
    }
};
