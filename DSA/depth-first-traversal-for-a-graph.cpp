// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
  
    void solve(vector<vector<int>>& adj,vector<int>&ans,vector<bool>&vis,int n,int i){
        if(ans.size()==n){
            return;
        }
        
        vis[i] = true;
        ans.push_back(i);
        
        for(auto node : adj[i]){
            if(!vis[node]){
                
                solve(adj,ans,vis,n,node);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int>ans;
        int n=adj.size();
        vector<bool>vis(n,0);
        solve(adj,ans,vis,n,0);
        
        return ans;
    }
};
