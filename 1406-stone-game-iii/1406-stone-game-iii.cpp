class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int next1 = 0;
        int next2 = 0;
        int next3 = 0;
        for(int i = n - 1; i >= 0; i--) {
            int ans = stoneValue[i] - next1;
            if(i + 1 < n) {
                ans = max(ans,stoneValue[i] + stoneValue[i + 1] - next2);
            }
            if(i + 2 < n) {
                ans = max(ans,stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - next3);
            }
            next3 = next2;
            next2 = next1;
            next1 = ans;
        }
        if(next1 > 0) {
            return "Alice";
        }
        if(next1 < 0) {
            return "Bob";
        }
        return "Tie";
    }
};