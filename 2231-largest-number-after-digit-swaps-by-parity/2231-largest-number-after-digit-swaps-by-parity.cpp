class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        priority_queue<int>even;
        priority_queue<int>odd;
        for(char ch:s){
            if((ch-'0')%2==0){
                even.push(ch);
            }
            else{
                odd.push(ch);
            }

        }
        for(int i=0;i<s.size();i++){
            if((s[i]-'0')%2==0){
                s[i]=even.top();
                even.pop();
            }
            else{
                s[i]=odd.top();
                odd.pop();
            }
        }
        return stoi(s);
    }
};