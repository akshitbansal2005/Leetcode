class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    // grid[i][j]='0';
                    bfs(grid,i,j,m,n);
                }
            }
        }
        return cnt;
    }
    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        queue<pair<int, int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 &&nr<m && nc>=0&&nc<n && grid[nr][nc]=='1'){
                    grid[nr][nc]='0';
                    q.push({nr,nc});
                }
            }
        }
    }
};