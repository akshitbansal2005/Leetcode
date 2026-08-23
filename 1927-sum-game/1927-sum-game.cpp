class Solution {
public:
    bool sumGame(string num) {
        int n =num.size();
        int half= n>>1;
        int QL=0,QR=0, diff=0;
        for(int i=0;i<n;i++){
            if(i<half){
                if(num[i]=='?'){
                    QL++;
                }
                else diff+=num[i]-'0';
            }
            else{
                if(num[i]=='?'){
                    QR++;
                }
                else diff-=num[i]-'0';
            }
        }
        if((QL+QR)&1){
            return true;
        }
        return diff!=9*(QR-QL)>>1;
    }
};