class Solution {
public:
    int solve(int i,int jump,bool prev,auto& dp,int k){
        if(i>=k+2) return 0;
        if(dp.find({i,jump,prev})!=dp.end()) return dp[{i,jump,prev}];
        int ans= i==k? 1:0;
        if(prev && i>0)
            ans+=solve(i-1,jump,false,dp,k);
        
        ans+=solve(i+(1<<jump),jump+1,true,dp,k);
        return dp[{i,jump,prev}]=ans;
    }
    int waysToReachStair(int k) {
        map<array<int,3>,int> dp;
        return solve(1,0,true,dp,k);
    }
};