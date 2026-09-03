class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n<=1) return true;
        int minElement = nums1[0];
        for(int i=1;i<n;i++){
            if(nums1[i]< minElement){
                minElement = nums1[i];
            }
        }
        if(minElement % 2!=0){
            return true;
        }
        else{
            for(int x: nums1){
                if(x%2!=0){
                    return false;
                }
            }
        }
        return true;
    }
};