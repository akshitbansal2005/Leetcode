class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<pair<int,int>> v;
        for (int c=0;c<n;c++) {
            int l =c,r= c;
            while(l >= 0 &&r<n &&s[l]== s[r]){
                if(r-l+1>= k){
                    v.push_back({l,r});
                }
                l--;
                r++;
            }
            l = c;
            r = c + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    v.push_back({l, r});
                }
                l--;
                r++;
            }
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second <b.second;
        });
        int ans=0;
        int last=-1;
        for (auto &p:v) {
            if(p.first>last){
                ans++;
                last =p.second;
            }
        }
        return ans;
    }
};