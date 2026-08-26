class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0,j=0;
        int n=s.size();
        int cnt=0;
        int mini=1e9;
        string res="";
        while(j<n){
            if(s[j]=='1'){
                cnt++;
            }
            while(i <= j&& cnt >k){
                if(s[i] =='1'){
                    cnt--;
                }
                i++;
            }
            if(cnt==k){
                while(i<=j&&s[i]=='0'){
                    i++;
                }
                if(j-i+1<mini){
                    mini=j-i+1;
                    res=s.substr(i,j-i+1);
                }
                if(j-i+1==mini){
                    res=min(res,s.substr(i,j-i+1));
                }
            }
            j++;
        }
        return res;
    }
};