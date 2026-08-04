class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minElement=*min_element(nums.begin(), nums.end());
        int maxElement=*max_element(nums.begin(), nums.end());
        vector<bool> exists(maxElement-minElement+1);
        for(int& i:nums) exists[i-minElement]=true;
        vector<int>ans;
        for(int i =0;i<maxElement-minElement;i++){
            if(!exists[i]){
                ans.push_back(i+minElement);
            }
        }
        return ans;
    }
};