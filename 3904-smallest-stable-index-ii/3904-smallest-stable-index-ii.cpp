class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>lgst(n);
        vector<int>smllst(n);
        lgst[0]=nums[0];
        for(int i=1;i<n;i++){
            lgst[i]=max(lgst[i-1],nums[i]);
            }
            smllst[n-1]=nums[n-1];
            for(int i=n- 2;i>= 0;i--) {
            smllst[i]=min(smllst[i+1],nums[i]);
        }
        for(int i=0;i< n;i++) {
            if(lgst[i]-smllst[i]<= k) {
                return i;
            }
        }
        return -1;
    }
};