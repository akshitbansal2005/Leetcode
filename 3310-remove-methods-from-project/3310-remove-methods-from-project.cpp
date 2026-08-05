class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        sort(invocations.begin(), invocations.end());
        vector<int> bad(n, 0);
        queue<int> q;
        bad[k] = 1;
        q.push(k);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            auto it = lower_bound(invocations.begin(), invocations.end(),vector<int>{x, -1});
            while(it != invocations.end() && (*it)[0] == x) {
                int y = (*it)[1];
                if(bad[y] == 0) {
                    bad[y] = 1;
                    q.push(y);
                }

                it++;
            }
        }
        for(auto v : invocations) {
            int a = v[0];
            int b = v[1];

            if(bad[a] == 0 && bad[b] == 1) {
                vector<int> ans;
                for(int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(bad[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};