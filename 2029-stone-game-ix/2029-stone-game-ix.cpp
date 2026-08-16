class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] ={0,0,0};
        for(int i=0;i<stones.size();i++) {
            cnt[stones[i]%3]++;
        }
        if(cnt[0]%2==0) {
            if(cnt[1]>0 &&cnt[2]> 0) {
                return true;
            }
            return false;
        }
        else {
            int difference = abs(cnt[1]-cnt[2]);
            if(difference >2) {
                return true;
            }
            return false;
        }
    }
};