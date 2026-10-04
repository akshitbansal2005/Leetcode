class Solution {
public:
    bool checkValidString(string s) {
        int max=0, min=0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                max++;
                min++;
            }
            else if(s[i] == ')'){
                min--;
                max--;
            }
            else if(s[i] == '*'){
                min--;
                max++;
            }
            if(min<0) min=0;
            if(max<0) return false;
        }
        if(min!=0) return false;
        return true;
        
    }
};