class Solution {
public:
    int maximumLengthSubstring(string s) {

        int l =0;

        int r=0;
        int maxi=INT_MIN;
        unordered_map<char, int>mp;
        while(r<s.size()){
            mp[s[r]]+=1;
            while(mp[s[r]]>2){
                mp[s[l]]-=1;
                l++;
            }
            maxi=max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};