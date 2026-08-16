class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};
        for(int i=0;i<stones.size();i++) {
            cnt[stones[i]%3]++;
        }
        if(cnt[0]%2==0) {
            return cnt[1]&&cnt[2];

        }
        return abs(cnt[2]-cnt[1])>2;
    }
};