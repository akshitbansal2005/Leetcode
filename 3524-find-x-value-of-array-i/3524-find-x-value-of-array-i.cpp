class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>ans(k);
        vector<long long>last(k);
        for (int x :nums){
            vector<long long>now(k,0);
            int val= x%k;
            now[val]++;
            for (int i=0;i< k;i++){
                if(last[i]==0) continue;
                int rem=(i*val)%k;
                now[rem]+=last[i];
            }
            for(int i=0;i<k;i++){
                ans[i] +=now[i];

            }
            last = now;
        }

        return ans;
    }
};