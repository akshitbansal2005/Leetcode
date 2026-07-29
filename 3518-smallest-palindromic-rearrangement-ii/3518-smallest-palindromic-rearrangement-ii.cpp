class Solution {
public:
    long long calculateCombination(int n, int r, long long limit) {
        r = min(r, n - r);
        long long answer = 1;
        for (int i = 1; i <= r; i++) {
            answer = answer * (n - r + i) / i;
            if (answer >= limit) {
                return limit;
            }
        }
        return answer;
    }
    long long countPermutations(vector<int>& frequency, long long limit) {
        long long ways = 1;
        int charactersUsed = 0;

        for (int count : frequency) {
            if (count == 0) {
                continue;
            }
            long long combinations = calculateCombination(
                charactersUsed + count,
                count,
                limit
            );
            if (ways >= limit || combinations >= limit) {
                return limit;
            }
            if (ways > limit / combinations) {
                return limit;
            }
            ways *= combinations;
            if (ways >= limit) {
                return limit;
            }
            charactersUsed += count;
        }
        return ways;
    }
    string smallestPalindrome(string s, int k) {
        vector<int> frequency(26, 0);
        for (char ch : s) {
            frequency[ch - 'a']++;
        }
        auto prelunthak = make_pair(s, k);
        vector<int> halfFrequency(26, 0);
        char middleCharacter = '\0';
        for (int i = 0; i < 26; i++) {
            halfFrequency[i] = frequency[i] / 2;
            if (frequency[i] % 2 == 1) {
                middleCharacter = char('a' + i);
            }
        }
        long long totalWays = countPermutations(halfFrequency, k);
        if (totalWays < k) {
            return "";
        }
        int halfLength = s.size() / 2;
        string leftHalf;
        for (int position = 0; position < halfLength; position++) {
            bool characterSelected = false;

            for (int letter = 0; letter < 26; letter++) {
                if (halfFrequency[letter] == 0) {
                    continue;
                }
                halfFrequency[letter]--;

                long long ways =
                    countPermutations(halfFrequency, k);

                if (ways >= k) {
                    leftHalf += char('a' + letter);
                    characterSelected = true;
                    break;
                }
                k -= ways;
                halfFrequency[letter]++;
            }
            if (!characterSelected) {
                return "";
            }
        }
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        string answer = leftHalf;
        if (middleCharacter != '\0') {
            answer += middleCharacter;
        }
        answer += rightHalf;
        return answer;
    }
};