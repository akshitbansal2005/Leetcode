class Solution {
public:
/*to isme hum level wise check krege to bfs lagega
like eg1:- [0 0 0
        0 1 0
        1 1 1]
        iska jo output aayega vo aayega (0,0,0)(0,1,0)(1,2,1) 
    eg2- [0 0 1
          1 0 0
          1 1 1]
          iska output aayega (0 0 1)(1 0 0)(2 1 1)
        so simply what im thinking is that if we can make a vis[] matx and check level wise ki \
        nearest 0 for each cell ky hoga? 
        */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int, int>, int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j}, 0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;

                }
            }
        }
        int delcol[]={0,1,0,-1};
        int delrow[]={-1,0,1,0};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int s=q.front().second;
            q.pop();
            ans[row][col]=s;
            for(int i=0;i<4;i++){
                int nr=row+delrow[i];
                int nc=col+delcol[i];
                if(nr>=0 && nr<n &&nc>=0 &&nc<m && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},s+1});
                }
            }
        }
    return ans;

    }
};