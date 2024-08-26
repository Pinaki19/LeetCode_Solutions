class Solution {
public:
    bool solve(string& s,string& p,int i,int j,auto& dp){
        if(i>=s.size()){
            while(j<p.size() && p[j]=='*')
                j++;
            return j>=p.size();
        }
        if(j>=p.size()) return i>=s.size();
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?')
            return dp[i][j]=solve(s,p,i+1,j+1,dp);
        if(p[j]=='*'){
            bool ans=false;
            for(int k=i;k<=s.size();k++){
                ans|=solve(s,p,k,j+1,dp);
                if(ans) break;
            }
            return dp[i][j]=ans;
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        string tp="";
        char prev='1';
        for(char c:p){
            if(c=='*' && prev=='*') continue;
            prev=c;
            tp+=c;
        }
        p=tp;
        int m=s.size();
        int n=p.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(s,p,0,0,dp);
    }
};