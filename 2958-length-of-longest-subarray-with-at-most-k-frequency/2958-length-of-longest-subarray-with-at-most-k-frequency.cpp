class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int, int> mp;
        int i = 0;
        int maxLen = 0;
        for(int j=0;j<n;j++) {
            mp[nums[j]]++;
            while(mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }
            int currLen = j - i + 1;
            if(currLen > maxLen) {
                maxLen = currLen;
            }
        }
        return maxLen;
    }
};