// https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
  
    void solve(vector<int>adj[], vector<int>&vis,stack<int>&st,int node){
        vis[node] = true;
        
        for(auto neigh : adj[node]){
            if(!vis[neigh]){
                solve(adj,vis,st,neigh);
            }
        }
        
        st.push(node);
        
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>adj[V];
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int>vis(V,0);
        stack<int>st;
        
        for(int i=0; i<V;i++){
            if(!vis[i]){
                solve(adj,vis,st,i);
            }
        }
        
        vector<int>ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
