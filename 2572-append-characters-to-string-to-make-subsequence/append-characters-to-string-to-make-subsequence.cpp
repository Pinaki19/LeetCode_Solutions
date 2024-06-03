class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        for(;i<s.size();i++){
            if(s[i]==t[j]) j++;
        }

        return t.size()-j;
    }
};