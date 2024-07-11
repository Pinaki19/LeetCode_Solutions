class Solution {
public:
    static string reverseParentheses(string& s) {
        string ans, rev;
        for(char c: s){
            if (c!=')') ans.push_back(c);
            else{
                rev="";
                for(char r=ans.back(); r!='('; r=ans.back()){
                    rev+=r;
                    ans.pop_back();
                }
                ans.pop_back();
                ans+=rev;
            }
        }
        return ans;
    }
};

