class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int scr=0;
            for(int j=1;j<n;j++){
                // scr+=(s[j]==s[j-1]);
                scr+=(s[(i+j)%n]==s[(i+j-1)%n]);
            }
            if(scr==k){
                ans++;
            }
        }
        return ans;
    }
};