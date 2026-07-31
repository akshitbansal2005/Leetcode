class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        vector<int> f(26,0);
        for(char &c:word){
            f[c-'a']++;

        }
        sort(f.begin(), f.end(), greater<int>());
        for(int i=0;i<26;i++){
            int freq=f[i];
            int word=(i/8+1);
            ans+=word*freq;
        }
        return ans;
    }
};