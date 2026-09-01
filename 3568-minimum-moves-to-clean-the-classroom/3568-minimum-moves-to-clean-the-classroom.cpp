class Solution {
public:




/*We use BFS to find the minimum moves. Each state stores our position
remaining energy, and a bitmask showing which litter has been collected
Energy decreases on every move and resets at R. We keep the maximum energy
for each position and mask to avoid unnecessary states
When all litter is collected, BFS gives the minimum number of moves*/





    int minMoves(vector<string>& classroom,int energy){
        int m=classroom.size(),n=classroom[0].size();
        int sr=0,sc=0;
        vector<pair<int,int>> litter;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    sr=i;sc=j;
                }
                else if(classroom[i][j]=='L'){
                    litter.push_back({i,j});

                }
            }
        }
        int k=litter.size();
        if(k==0)return 0;
        vector<vector<int>> id(m,vector<int>(n,-1));
        for(int i=0;i<k;i++){
            id[litter[i].first][litter[i].second]=i;

        }

        int fullMask=(1<<k)-1;
        vector<vector<vector<int>>>best(m,vector<vector<int>>(n,vector<int>(1<<k,-1)));
        queue<tuple<int,int,int,int>> q;
        q.push({sr,sc,0,energy});
        best[sr][sc][0]=energy;
        int moves=0;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [r,c,mask,rem]=q.front();
                q.pop();
                if(mask==fullMask)return moves;
                if(rem==0)continue;
                for(int d=0;d<4;d++){
                    int nr=r+dr[d],nc=c+dc[d];
                    if(nr<0||nr>=m||nc<0||nc>=n||classroom[nr][nc]=='X'){
                        continue;

                    }
                    int newEnergy=rem-1;
                    int newMask=mask;
                    if(classroom[nr][nc]=='R'){
                        newEnergy=energy;
                        
                    }

                    if(id[nr][nc]!=-1){
                        newMask|=(1<<id[nr][nc]);

                    }
                    if(best[nr][nc][newMask]<newEnergy){
                        best[nr][nc][newMask]=newEnergy;
                        q.push({nr,nc,newMask,newEnergy});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};