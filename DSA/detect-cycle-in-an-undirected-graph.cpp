// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
  
   bool dfs(int node,int parent, vector<int>&vis,vector<int>adj[]){
       vis[node]=1;
       
       for(auto neigh:adj[node]){
           if(!vis[neigh]){
               if(dfs(neigh,node,vis,adj)){
                   return true;
               }
               
           }
           else if(neigh != parent){
               return true;
           }
       }
       return false;
   }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>adj[V];
        
        for(int i=0; i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);
        
        for(int i=0; i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};
