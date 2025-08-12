https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1


class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        
         vector<vector<int>>ans(n,vector<int>(m,-1));
         
         for(int i=0; i<n; i++){
             for(int j=0; j<m;j++){
                 if(grid[i][j]==1){
                     ans[i][j] = 0;
                     q.push({i,j});
                 }
             }
         }
         
         int dist = 0;
         int dx[4]={-1,1,0,0};
         int dy[4] = {0,0,-1,1};
         
         while(!q.empty()){
             int size = q.size();
             dist++;
             while(size--){
                 auto it = q.front();
                 int i = it.first;
                 int j = it.second;
                 q.pop();
                 
                 for(int a=0;a<4;a++){
                     int x = i+dx[a];
                     int y = j+dy[a];
                     
                     if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0){
                         ans[x][y] = dist;
                         grid[x][y] = 1;
                         q.push({x,y});
                     }
                 }
             }
         }
         return ans;
    }
};
