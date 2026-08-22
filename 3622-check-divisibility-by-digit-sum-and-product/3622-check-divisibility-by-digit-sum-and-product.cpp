class Solution {
public:



/* 2 functions bana lege like -> prod and sum jisme
     sum =0, and product =1 and num%10 lege because to find the last digit
        and last mei return krdege   */
    int prod(int n){
        int num=n;
        int ans =1;
        while(num!=0){
            ans*=(num%10);
            num/=10;
        }
        return ans;
    }
    int sum(int n){
        int num=n;
        int ans =0;
        while(num!=0){
            ans+=(num%10);
            num/=10;
        }
        return ans;
    }
    bool checkDivisibility(int n) {
        return n %(prod(n)+sum(n))==0;
    }
};