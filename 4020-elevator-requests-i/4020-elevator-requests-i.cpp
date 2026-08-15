class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans=0, ele=0;
        for(int i =0;i<requests.size();i++){
            while(ele!=requests[i]){
                if(ele<requests[i]){
                    ele++, ans++;
                }
                else ele--, ans++;

            }
        }
        return ans;
    }
};