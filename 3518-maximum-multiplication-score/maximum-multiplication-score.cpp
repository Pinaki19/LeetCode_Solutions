class Solution {
public:
    using ll=long long;
    ll solve(int i,int j,auto& a,auto& b,auto& dp){
        if(i>=a.size()) return 0;
        if(j>=b.size()) return LLONG_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        ll ans=solve(i,j+1,a,b,dp);
        ll next=solve(i+1,j+1,a,b,dp);
        ll t= next==LLONG_MIN? LLONG_MIN:(a[i]*1ll*b[j])+next;
        ans=max(t,ans);
        return dp[i][j]=ans;
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<ll>> dp(4, vector<ll>(n, -1));
        ll ans=solve(0,0,a,b,dp);
        return ans==INT_MIN? -1:ans;
    }
};