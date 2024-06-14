class Solution {
public:
    int getMax(int i,int cur,auto& rew,int* dp){
        if(i>=rew.size()||cur>rew.back()) return 0;
        if(dp[cur]>=0) return dp[cur];
        if(rew[i]<=cur) return dp[cur]=getMax(i+1,cur,rew,dp);
        int iftake=cur+rew[i];
        int pos=lower_bound(rew.begin()+i,rew.end(),iftake)-rew.begin();
        return dp[cur]=max(rew[i]+getMax(pos,iftake,rew,dp),getMax(i+1,cur,rew,dp));
    }
    int maxTotalReward(vector<int>& reward) {
        int n=0;
        sort(reward.begin(),reward.end());
        int dp[4000];
        memset(dp,-1,sizeof(dp));
        int ans= getMax(0,0,reward,dp);
        return ans;
    }
};