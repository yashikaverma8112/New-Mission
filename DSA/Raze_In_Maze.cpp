class Solution {
  public:
    
    
    bool isSafe(int newX, int newY, vector<vector<int>>&maze, vector<string>&ans, 
    vector<vector<bool>>&visited,int n)
    
    {
            return (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                maze[newX][newY] == 1 && !visited[newX][newY]);
    }
    
    void solve(vector<vector<int>>&maze, vector<string>&ans, vector<vector<bool>>&visited,
    string path, int x, int y,int n)
    {
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y]=true;
        // Down
        if(isSafe(x+1,y,maze,ans,visited,n)){
            solve(maze,ans,visited,path+'D',x+1,y,n);
        }
        //Left
        if(isSafe(x,y-1,maze,ans,visited,n)){
            solve(maze,ans,visited,path+'L',x,y-1,n);
        }
        //Right
        if(isSafe(x,y+1,maze,ans,visited,n)){
            solve(maze,ans,visited,path+'R',x,y+1,n);
        }
        //Up
        if(isSafe(x-1,y,maze,ans,visited,n)){
            solve(maze,ans,visited,path+'U',x-1,y,n);
        }
        
        visited[x][y]=0;
        
    } 
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string>ans;
        int n = maze.size();
        if(maze[0][0]==0){
            return ans;
        }
        
        string path = "";
        vector<vector<bool>>visited(n,vector<bool>(n,0));
        
        solve(maze, ans, visited, path,0,0,n);
        
        return ans;
    }
};
