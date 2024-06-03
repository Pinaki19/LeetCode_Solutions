class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(0);
        int i=0,j=0;
        for(;i<s.size() && j<t.size();i++){
            if(s[i]==t[j]) j++;
        }

        return t.size()-j;
    }
};