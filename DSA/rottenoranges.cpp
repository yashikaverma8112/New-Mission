class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int res =  0, cnt = 0;
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>>q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n;j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }
                
                if(mat[i][j]==1){
                    cnt++;
                }
            }
        }
        
        if(cnt==0){
            return 0;
        }
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        while(!q.empty() && cnt > 0){
            res++;
            int size = q.size();
            
            for(int k =0; k<size; k++){
                int i = q.front().first;
                int j = q.front().second;
                
                q.pop();
                
                for(int a=0; a<4; a++){
                    int x = i+dx[a];
                    int y = j+dy[a];
                    
                    if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1){
                        mat[x][y] = 2;
                        cnt--;
                        q.push({x,y});
                    }
                }
            }
        }
        
        if(cnt > 0){
            return -1;
        }        
        
        return res;
    }
};
