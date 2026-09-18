class Solution {
public:
    vector<string> maxNumOfSubstrings(string s){
        int n = s.size();
        vector<int> l(26, n), r(26, -1);
        for(int i =0;i<n;i++){
            int ch =s[i] -'a';
            l[ch] =min(l[ch],i);
            r[ch] =i;
        }
        vector<pair<int,int>> arr;
        for(int i =0;i <26;i++){
            if(r[i] ==-1) continue;

            int left =l[i];
            int right= r[i];
            bool flag =true;

            for(int j =left;j <= right;j++){
                int ch = s[j]-'a';

                if(l[ch]<left){
                    flag=false;
                    break;
                }
                if(r[ch]>right)
                    right =r[ch];
            }
            if(flag){
                arr.push_back({left, right});

            }
        }
        sort(arr.begin(),arr.end(),[](auto &a, auto &b){
            return a.second < b.second;
        });
        vector<string>ans;
        int last=-1;
        for(auto x:arr) {
            if(x.first>last){
                ans.push_back(s.substr(x.first,x.second-x.first + 1));
                last = x.second;
            }
        }
        return ans;
    }
};