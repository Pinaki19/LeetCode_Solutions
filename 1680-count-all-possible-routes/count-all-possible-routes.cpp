class Solution {
public:
    const int MOD=(int)1e9+7;
    int solve(auto& locations,int start,int finish,int fuel,auto& dp){
        long ans=0;
        if(fuel<0)
            return 0;
        if(dp[start][fuel]>=0) return dp[start][fuel];
        if(start==finish) ans++;
        for(int i=0;i<locations.size();i++){
            if(i==start) continue;
            ans+=solve(locations,i,finish,fuel-abs(locations[i]-locations[start]),dp)%MOD;
            ans%=MOD;
        }
        return  dp[start][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(101,vector<int> (201,-1));
        return solve(locations,start,finish,fuel,dp);
    }
};