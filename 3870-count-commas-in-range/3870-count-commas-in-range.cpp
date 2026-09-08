class Solution {
public:
    int countCommas(int n) {
        long long ans =0;
        if(n>=1000)
            ans +=(n-1000+1)*1;
        if(n>=1000000)
            ans +=(n-1000000 + 1)*2;
        if(n>=1000000000)
            ans+= (n - 1000000000 + 1)*3;
        return ans;        
    }
};