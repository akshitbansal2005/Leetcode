class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        int numbers=n/8;
        return (numbers*(numbers+1)*4)+(n%8)*(numbers+1);
    }
};