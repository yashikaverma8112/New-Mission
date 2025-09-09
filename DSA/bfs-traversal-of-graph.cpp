// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool>vis(n,0);
        vector<int>ans;
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto i : adj[front]){
                if(!vis[i]){
                    vis[i] = true;
                    q.push(i);
                }
            }
            
        }
        return ans;
    }
};
