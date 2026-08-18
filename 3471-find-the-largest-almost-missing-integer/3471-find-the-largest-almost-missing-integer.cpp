class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n) return *max_element(nums.begin(), nums.end());
        else{
            unordered_map<int, int>map;
            for(int i =0;i<nums.size()-k+1;i++){
                for(int j =i;j<i+k;j++){
                    map[nums[j]]++;
                }
            }
            int ans=-1;
            for(const auto& [n,f]:map){
                if(f==1&& n>ans){
                    ans=n;
                }
            }
            return ans;
        }
    }
};