class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(char c:s)
            temp+=to_string((int)(c-'a')+1);
        int cur=0;
        while(k--){
            cur=0;
            for(char c:temp)
                cur+=c-'0';
            temp=to_string(cur);
        }
        return cur;
    }
};