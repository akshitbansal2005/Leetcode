class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for(int i=0;i<n;i++){
            total +=nums[i];
        }
        int target= total-x;
        if(target<0){
            return -1;
        }
        int left = 0;
        int sum = 0;
        int maxi = -1;

        for(int right =0;right<n;right++){
            sum +=nums[right];
            while(sum>target){
                sum -=nums[left];
                left++;
            }
            if(sum==target){
                maxi =max(maxi,right-left+1);
            }
        }
        if(maxi ==-1){
            return -1;
        }

        return n - maxi;
    }
};