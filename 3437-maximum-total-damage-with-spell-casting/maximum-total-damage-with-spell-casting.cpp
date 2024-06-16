#define ll long long
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int> mp;
        for(int i:power) mp[i]++;
        ll ans=0;
    
        set<int> s(power.begin(),power.end());
        vector<int> pn(s.begin(),s.end());
        int n=pn.size();
        ll dp[n];
        fill(dp,dp+n,0);
        
        for(int i=0;i<n;i++){
            ll prev=0;
            int j=i-1;
            ll M=0;
            while(j>=0 && pn[i]-pn[j]<=2){
                M=max(M,dp[j]);
                j--;    
            } 
            if(j>=0 && pn[i]-pn[j]>2) prev=dp[j];
            dp[i]=max(pn[i]*1ll*mp[pn[i]]+prev,M);
        }
        return dp[n-1];
    }
};