class Solution {
public:
    int m, n;
    set<tuple<int,int,int>> vis;
    bool dfs(vector<vector<char>>& grid, int i, int j, int balance){
        if (grid[i][j] == '('){
            balance++;
        }
        else balance--;
        if(balance< 0){
            return false;
        }
        int left = (m - 1 - i) + (n - 1 - j);
        if(balance>left){
            return false;
        }
        if(i == m -1 && j==n - 1){
            return balance == 0;

        }
        auto state = make_tuple(i,j,balance);
        if(vis.count(state)){
            return false;
        }
        vis.insert(state);
        if(i + 1<m){
            if(dfs(grid, i + 1, j, balance)){
                return true;
            }
        }
        if(j+1<n){
            if (dfs(grid, i, j + 1, balance)){
                return true;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<char>>& grid){
        m = grid.size();
        n = grid[0].size();
        int len =m+n-1;
        if (len % 2 != 0){
            return false;
        }
        if (grid[0][0] == ')'){
            return false;
        }
        vis.clear();
        return dfs(grid, 0, 0, 0);
    }
};