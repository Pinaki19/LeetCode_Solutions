class Solution {
public:
    int solve(int ind,int mask,auto& v,auto&dp,auto& mp){
        if(ind>=v.size()) return 0;
        if(dp[ind][mask]>=0) return dp[ind][mask];
        int ans=solve(ind+1,mask,v,dp,mp);
        int val=v[ind];
        for(int t:mp[val]){
            if((mask>>t)&1) continue;
            ans=max(ans,val+solve(ind+1,mask|(1<<t),v,dp,mp));
        }

        return dp[ind][mask]=ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        map<int,vector<int>> mp;
        set<int,greater<>> s;
        int m=grid.size();
        for(int i=0;i<m;i++){
            for(int j:grid[i]){
                mp[j].push_back(i);
                s.insert(j);
            }
        }
        vector<int> v(s.begin(),s.end());
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>((1<<10)+1,-1));
        return solve(0,0,v,dp,mp);
    }
};