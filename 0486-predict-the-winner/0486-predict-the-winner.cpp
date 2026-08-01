class Solution {
public:

    int assume(vector<int>& nums,int left, int right){
        if(left==right){
            return nums[left];
        }
        int takeLeft= nums[left]-assume(nums,left+1, right);
        int takeRight=nums[right]-assume(nums, left, right-1);
        return max(takeLeft, takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int score=assume(nums,0,n-1);
        if(score>=0){
            return true;
        }
        return false;
    }
};