class Solution {
public:


 /* this quesion seems to be a little hard burt nvm we'll try it xd
    as we can see its mentioned in question that both having len 'n' 
    and consisting of LC eng letter its a clear indication that you you want
    to make a string you must use array of 26 alphabetic letters(size is fixed)
    
    case-->> 
    s= aab ac
    t= aac bc 
    see if there is any difference we can see b< c (aabac<aacbc)*/


    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (int i = 0;i<n;i++) {
            count[s[i] -'a']++;
        }
        string result= "";
        for (int i=0;i< n;i++) {
            int targetChar =target[i]-'a';
            if (count[targetChar]> 0) {
                count[targetChar]--;
                if (canMakeGreater(count,target,i+ 1)) {
                    result +=target[i];
                    continue;
                }
                count[targetChar]++;
            }
            for(int c=targetChar+1;c<26;c++) {
                if (count[c]>0) {

                    result+=char('a'+c);
                    count[c]--;
                    for(int j=0;j<26;j++) {
                        while(count[j]> 0) {
                            result +=char('a'+ j);
                            count[j]--;
                        }
                    }
                    return result;
                }
            }
            return "";
        }
        return "";
    }
private:
    bool canMakeGreater(vector<int>& count,string target,int start){
        string largest = "";
        for(int c =25;c>=0;c--) {
            while(count[c]> 0) {
                largest +=char('a'+c);
                count[c]--;
            }
        }
        for(int i =0;i< largest.length();i++) {
            count[largest[i] -'a']++;
        }
        string targetSuffix = target.substr(start);
        return largest > targetSuffix;
    }
};