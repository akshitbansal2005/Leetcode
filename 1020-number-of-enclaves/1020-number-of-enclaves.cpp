class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {   
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int t = 0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    t+=1;
                    if(i==0 || j==0 || i==(m-1) || j==(n-1)){
                        vis[i][j] = true;
                        t-=1;
                        q.push({i,j});
                    }  
                }
            }
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [x, y] = q.front();
                q.pop();
                for(int d =0;d<4;d++){
                    int nx = x+dx[d];
                    int ny = y+dy[d];
                    if(nx>0 && ny>0 && nx<m && ny<n && grid[nx][ny]==1 && !vis[nx][ny]){
                        vis[nx][ny] = true;
                        t-=1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return t;
    }
};