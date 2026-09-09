class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for(long long p = 1000, c=1;p<=n;p*=1000, c++){
            long long r = min(n,p*1000-1);
            ans +=(r-p+1)*c;
        }
        return ans;
    }
};