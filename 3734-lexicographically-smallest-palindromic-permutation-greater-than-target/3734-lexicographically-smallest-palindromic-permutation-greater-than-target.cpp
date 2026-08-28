class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        int m=n/2;
        vector<int> freq(26,0);
        for(char c:s) {
            freq[c-'a']++;
        }
        int odd=0;
        int middle=0;
        for(int i=0;i<26;i++) {
            if(freq[i]%2) {
                odd++;
                middle='a'+i;
            }
        }
        if(odd>1) {
            return "";
        }
        vector<int> cnt(26);
        for(int i=0;i<26;i++) {
            cnt[i]=freq[i]/2;
        }
        int k=0; 
        while(k<m && cnt[target[k]-'a']>0) {
            cnt[target[k]-'a']--;
            k++;
        }
        if(k==m) {
            string left=target.substr(0,m);
            string right=left;
            reverse(right.begin(),right.end());
            string ans=left;
            if(n%2) {
                ans+=middle;
            }
            ans+=right;
            if(ans>target) {
                return ans;
            }
        }
        for(int i=k;i>=0;i--) {
            if(i==m) {
                continue;
            }
            if(i<k) {
                cnt[target[i]-'a']++;
            }
            int x=target[i]-'a';
            int bigger=-1;
            for(int c=x+1;c<26;c++) {
                if(cnt[c]>0) {
                    bigger=c;
                    break;
                }
            }
            if(bigger==-1) {
                continue;
            }
            string left=target.substr(0,i);
            left+=char('a'+bigger);
            cnt[bigger]--;
            for(int c=0;c<26;c++) {
                while(cnt[c]>0) {
                    left+=char('a'+c);
                    cnt[c]--;
                }
            }
            string right=left;
            reverse(right.begin(),right.end());
            if(n%2) {
                return left+string(1,middle)+right;
            }
            return left+right;
        }
        return "";
    }
};