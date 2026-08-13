class Solution {
public:

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int blockSize = sqrt(n) + 1;
        int totalBlocks = (n + blockSize - 1) / blockSize;
        vector<int> leftCnt(totalBlocks);
        vector<int> rightCnt(totalBlocks);
        vector<int> best(totalBlocks);
        vector<char> leftChar(totalBlocks);
        vector<char> rightChar(totalBlocks);
        auto updateBlock = [&](int block) {
            int start = block * blockSize;
            int end = min(n, start + blockSize);
            if(start >= n) return;
            leftChar[block] = s[start];
            rightChar[block] = s[end - 1];
            int cnt = 1;
            for(int i = start + 1; i < end; i++) {
                if(s[i] == s[start]){
                    cnt++;
                }
                else break;
            }

            leftCnt[block] = cnt;
            cnt = 1;
            for(int i = end - 2; i >= start; i--) {
                if(s[i] == s[end - 1]){
                    cnt++;
                }
                else break;
            }
            rightCnt[block] = cnt;
            int mx = 1;
            cnt = 1;
            for(int i = start + 1; i < end; i++) {
                if(s[i] == s[i - 1]) {
                    cnt++;
                }
                else {
                    cnt = 1;
                }
                mx = max(mx, cnt);
            }
            best[block] = mx;
        };
        for(int i = 0; i < totalBlocks; i++) {
            updateBlock(i);
        }
        vector<int> ans;
        for(int q = 0; q < queryIndices.size(); q++) {
            int index = queryIndices[q];
            char ch = queryCharacters[q];
            s[index] = ch;
            int changedBlock = index/blockSize;
            updateBlock(changedBlock);
            int answer = 0;
            int current = 0;
            char last = '#';
            for(int block = 0; block < totalBlocks; block++) {
                answer = max(answer, best[block]);
                int start = block * blockSize;
                int end = min(n, start + blockSize);
                int len = end - start;
                if(last == leftChar[block]) {
                    current += leftCnt[block];
                    answer = max(answer, current);
                }
                else {
                    current = leftCnt[block];
                }
                if(leftCnt[block] == len) {
                    last = leftChar[block];
                }
                else {
                    current = rightCnt[block];
                    last = rightChar[block];
                }
            }
            ans.push_back(answer);
        }
        return ans;
    }
};