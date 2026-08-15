class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool nonZero = false;
        for(int x :nums) {
            xr=xr ^ x;
            if(x!= 0) {
                nonZero =true;
            }
        }
        if(!nonZero) {
            return 0;
        }
        if(xr !=0) {
            return n;
        }
        return n-1;
    }
};