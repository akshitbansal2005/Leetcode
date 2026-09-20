class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        int product=0;
        for(int i=0;i<n;i++){
            int indx=s[i]-'a';
            int reverse= 26- indx;
            product=(i+1)*reverse;
            sum+=product;

        }
        return sum;
    }
};