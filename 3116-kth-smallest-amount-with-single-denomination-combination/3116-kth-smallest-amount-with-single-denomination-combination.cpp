// class Solution{
// public:
//     long long findKthSmallest(vector<int>& coins, int k) {
//         using Element = tuple<long long, int, long long>;
//         priority_queue<Element, vector<Element>, greater<Element>> pq;
//         for (int coin :coins) {
//             pq.push({coin,coin,1});
//         }
//         long long last_extracted = 0;
//         int count = 0;
//         while (!pq.empty()) {
//             auto [val,coin,mult] = pq.top();
//             pq.pop();
//             pq.push({coin*(mult +1),coin,mult +1});
//             if (val ==last_extracted) {
//                 continue;
//             }
//             last_extracted =val;
//             count++;
//             if (count==k) {
//                 return val;
//             }
//         }
//         return -1;
//     }
// };




class Solution {


    /*  ek function bana na hoga lcm calculate krne ke liye 2 numbers ka 
         unlike like the previous solution tle aagya lol
          jo bi multiple coins hoge unko remove krna hoga
           we can apply binary search */
    long long getLcm(long long a, long long b) {
        return (a /gcd(a, b)) * b;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        vector<int> filteredCoins;
        for (int i=0;i<coins.size();i++) {
            bool isRedundant = false;
            for (int j =0;j<filteredCoins.size();j++) {
                if (coins[i]%filteredCoins[j]==0) {
                    isRedundant=true;
                    break;
                }
            }
            if (isRedundant==false) {
                filteredCoins.push_back(coins[i]);
            }
        }

        int n = filteredCoins.size();
        vector<long long> lcms;
        vector<int> signs;
        int totalSubsets = 1 << n;
        for (int mask = 1; mask < totalSubsets; mask++) {
            long long currentLcm = 1;
            int count = 0;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    currentLcm = getLcm(currentLcm, filteredCoins[i]);
                    count++;
                }
            }
            lcms.push_back(currentLcm);
            if (count % 2 == 1) {
                signs.push_back(1);
            } else {
                signs.push_back(-1);
            }
        }
        long long low = filteredCoins[0];
        long long high = (long long)filteredCoins[0] * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long totalMultiples = 0;
            for (int i = 0; i < lcms.size(); i++) {
                totalMultiples += signs[i] * (mid / lcms[i]);
            }

            if (totalMultiples >= k) {
                ans = mid;
                high = mid-1; 
            } 
            else {
                low = mid+1; 
            }
        }
        
        return ans;
    }
};