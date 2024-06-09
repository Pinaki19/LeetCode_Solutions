class Solution {
public:
    int getMax(int i,int cur,auto& rew,auto& dp){
        if(i>=rew.size()||cur>rew.back()) return 0;
        if(dp.find(cur)!=dp.end()) return dp[cur];
        if(rew[i]<=cur) return dp[cur]=getMax(i+1,cur,rew,dp);
        int iftake=cur+rew[i];
        int pos=lower_bound(rew.begin()+i,rew.end(),iftake)-rew.begin();
        return dp[cur]=max(rew[i]+getMax(pos,iftake,rew,dp),getMax(i+1,cur,rew,dp));
    }
    int maxTotalReward(vector<int>& reward) {
        ios_base::sync_with_stdio(0);
        int n=0;
        sort(reward.begin(),reward.end());
        map<int,int> dp;
        int ans= getMax(0,0,reward,dp);
        return ans;
    }
};