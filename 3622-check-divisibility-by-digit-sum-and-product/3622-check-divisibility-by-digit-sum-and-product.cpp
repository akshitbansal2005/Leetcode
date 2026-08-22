class Solution {
public:



/* 2 functions bana lege like -> prod and sum jisme
     sum =0, and product =1 and %10 lege just because of 0,1,2,3,4,5,6,7,8,9
        and last mei return krdege   */
    int prod(int n){
        int num=n;
        int res =1;
        while(num!=0){
            res*=(num%10);
            num/=10;
        }
        return res;
    }
    int sum(int n){
        int num=n;
        int res =0;
        while(num!=0){
            res+=(num%10);
            num/=10;
        }
        return res;
    }
    bool checkDivisibility(int n) {
        return n %(sum(n)+prod(n))==0;
    }
};