class Solution {
public:
    vector<vector<long> > dp;
    vector<long> pref;
    int helper(int i, int j, vector<int> &val) {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long l=0, r= pref[j+1]-pref[i];
        long ans=0;
        for(int s=i; s<j; ++s){
            l+=val[s];
            r-=val[s];
            if(l==r) ans = max( ans, l+ max(helper(i, s, val), helper(s+1, j, val)));
            else if(l<r) ans= max(ans, l+ helper(i,s, val));
            else ans= max(ans, r+ helper(s+1, j, val));
        }
        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& val) {
        int n=val.size();
        dp.assign(501, vector<long > (501, -1));
        pref.assign(501,0);
        for(int i=0; i<n; ++i) pref[i+1]= pref[i]+ val[i];
        return helper(0, n-1, val);
    }
};