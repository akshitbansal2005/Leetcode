class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        const int mod = 1e9 + 7;
        int m = mat.size();
        vector<int> mobius(151);
        for(int num = 1; num <= 150; num++) {
            int x = num;
            int primeCount = 0;
            bool hasSquare = false;
            for(int p = 2; p * p <= x; p++) {
                if(x % p == 0) {
                    int cnt = 0;
                    while(x % p == 0) {
                        x /= p;
                        cnt++;
                    }
                    if(cnt > 1) {
                        hasSquare = true;
                    }
                    primeCount++;
                }
            }
            if(x > 1) {
                primeCount++;
            }
            if(hasSquare) {
                mobius[num] = 0;
            }
            else if(primeCount % 2 == 0) {
                mobius[num] = 1;
            }
            else {
                mobius[num] = -1;
            }
        }
        long long ans = 0;
        for(int d = 1; d <= 150; d++) {
            if(mobius[d] == 0) {
                continue;
            }
            long long ways = 1;
            for(int i = 0; i < m; i++) {
                int count = 0;
                for(int j = 0; j < mat[i].size(); j++) {
                    if(mat[i][j] % d == 0) {
                        count++;
                    }
                }
                if(count == 0) {
                    ways = 0;
                    break;
                }
                ways = (ways * count) % mod;
            }
            ans = (ans + mobius[d] * ways) % mod;
        }
        if(ans < 0) {
            ans += mod;
        }
        return ans;
    }
};