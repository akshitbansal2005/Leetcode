class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n= nums.size();
        vector<int>pos;
        vector<int>neg;
        for(int ele:nums){
            if(ele<0) pos.push_back(ele);
        }
        for(int ele:nums){
            if(ele>=0) pos.push_back(ele);
        }

        sort(nums.begin(), nums.end());
        int a1= nums[0]*nums[1]*nums[n-1];
        int a2= nums[n-1]*nums[n-2]*nums[n-3];
        return max(a1, a2);
    }
};