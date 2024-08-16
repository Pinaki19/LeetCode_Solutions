class Solution {
public:
    const int MOD=(int)1e9+7;
    int solve(int i,int k,int end,auto& dp){
        if(k<0) return 0;
        int diff=abs(end-i);
        if(diff>k||((k-diff)&1)) return 0;
        if(dp.find({i,k})!=dp.end())
            return dp[{i,k}];
        long ans=i==end && k==0;
        ans+=solve(i+1,k-1,end,dp);
        ans%=MOD;
        ans+=solve(i-1,k-1,end,dp);
        ans%=MOD;
        return dp[{i,k}]=ans;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        map<array<int,2>,int> dp;
        return solve(startPos,k,endPos,dp);
    }
};