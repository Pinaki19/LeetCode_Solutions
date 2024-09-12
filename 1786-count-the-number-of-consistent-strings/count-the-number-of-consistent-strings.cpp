class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allowed_chars[26]={0};
        for(char c:allowed){
            allowed_chars[c-'a']=1;
        }
        int answer=0;
        for(string& s:words){
            bool ok=true;
            for(char c:s){
                if(!allowed_chars[c-'a']){
                    ok=false;
                    break;
                }
            }
            answer+=ok;
        }

        return answer;
    }
};