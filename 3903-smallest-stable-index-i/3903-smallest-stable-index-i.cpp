class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int lgst=nums[0];
            int smllst=nums[i];
            for(int j=0;j<=i;j++){
                lgst=max(lgst,nums[j]);
            }
            for(int j=i;j<n;j++){
                smllst=min(smllst,nums[j]);
            }
            if(lgst-smllst<=k){
                return i;
            }
        }
        return -1;
    }
};