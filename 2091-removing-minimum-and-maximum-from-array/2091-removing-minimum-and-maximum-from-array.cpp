class Solution {
public:

/*We find the positions of the minimum and maximum elements, then calculate 
deletions in three ways- both from the front, both from the back, or one from 
each side.Finally, we return the minimum of the three*/

    int minimumDeletions(vector<int>& nums) {
        int n =nums.size();
        int maxi=0, mini=0;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[mini]){
                mini=i;
            }
            if(nums[i]>nums[maxi]){
                maxi=i;
            }
            
        }
        int left=min(mini,maxi);
        int right=max(mini,maxi);
        int R=right+1;
        int L=n-left;
        int total=left+1+n-right;
        return min({R,L,total});

    }
};