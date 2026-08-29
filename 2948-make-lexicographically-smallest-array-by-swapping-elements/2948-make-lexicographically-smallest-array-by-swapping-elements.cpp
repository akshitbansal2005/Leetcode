class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n =nums.size();
        vector<int> ans(n);
        vector<pair<int, int>>a(n);
        for(int i=0;i<n;i++){
            a[i]={nums[i], i};

        }
        sort(a.begin(), a.end());
        int i =0;
        while(i<n){
            int j=i+1;
            while(j<n&& a[j].first-a[j-1].first<=limit){
                j++;
            }
            vector<int> tmp;
            for(int k=i;k<j;k++){
                tmp.push_back(a[k].second);
            }
            sort(tmp.begin(), tmp.end());
            for(int k=0;k<tmp.size();k++){
                ans[tmp[k]]= a[i+k].first;
            }
            i=j;
        }
        return ans;
    }
};