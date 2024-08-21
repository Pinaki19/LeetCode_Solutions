class Solution {
public:
    int dp[101][101];
    int solve(auto& s,int l,int r){
        if(l>r) return 0;
        if(l==r) return dp[l][r]=1;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r])
            return dp[l][r]=solve(s,l+1,r);
 
        int ans=1+solve(s,l+1,r);
        for(int j=l+1;j<=r;j++){
            if(s[j]==s[l])
                ans=min(ans,solve(s,l+1,j)+solve(s,j+1,r));
        }
        return dp[l][r]=ans;
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size()-1);
    }
};