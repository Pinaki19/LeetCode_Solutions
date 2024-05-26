class Solution {
public:
int mod=(int)1e9+7;
    int dp[100001][2][3];
    int solve(int day,int Abs,int Late){
        if(Abs>=2 || Late>=3) return 0;
        if(day<=0) return 1;
        if(dp[day][Abs][Late]!=-1) return dp[day][Abs][Late];
        long ans=solve(day-1,Abs,0)%mod;
        ans+=solve(day-1,Abs+1,0)%mod;
        ans%=mod;
        ans+=solve(day-1,Abs,Late+1)%mod;
        ans%=mod;
        return dp[day][Abs][Late]=(int) ans;
    }
    
    int checkRecord(int n) {
        fill(&dp[0][0][0],&dp[0][0][0]+(sizeof(dp)/sizeof(int)),-1);
        long ans=solve(n,0,0);
        return (int)ans%mod;
    }
};