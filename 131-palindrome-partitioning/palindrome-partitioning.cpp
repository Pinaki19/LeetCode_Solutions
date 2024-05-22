class Solution {
public:
    function<bool(string&)> isPalindrome=[](string& s)->bool{
        for(int i=0;i<=s.size()/2;i++)
            if(s[i]!=s[s.size()-i-1])
                return 0;
        return 1;
    };
    void solve(int i,string& s,auto& ans,auto& temp){
        if(i>=s.size()){
            ans.push_back(temp);
            return;
        }
        string t="";
        for(int j=i;j<s.size();j++){
            t+=s[j];
            if(isPalindrome(t)){
                temp.push_back(t);
                solve(j+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(0);
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0,s,ans,temp);
        return ans;
    }
};