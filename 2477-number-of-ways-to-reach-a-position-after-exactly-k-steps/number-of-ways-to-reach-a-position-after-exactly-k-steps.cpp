class Solution {
public:
    const int MOD=(int)1e9+7;
    int solve(int i,int k,int end,auto& dp){
        if(k<0) return 0;
        int diff=abs(end-i);
        if(diff>k||((k-diff)&1)) return 0;
        if(dp[i+1000][k]>=0) return dp[i+1000][k];
        long ans=i==end && k==0;
        ans+=solve(i+1,k-1,end,dp);
        ans%=MOD;
        ans+=solve(i-1,k-1,end,dp);
        ans%=MOD;
        return dp[i+1000][k]=ans;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(4000,vector<int>(1001,-1));
        return solve(startPos,k,endPos,dp);
    }
};