class Solution {
public:
 
    array<int,2> solve(bool alice,int i,int m,auto& psum,auto& dp){
        if(i>=psum.size())return {0,0};
        if(dp[alice][i][m][0]!=-1) return dp[alice][i][m];
        int a_score=0,b_score=0;
        for(int k=i;k<i+2*m;k++){
            if(k>=psum.size()) break;
            int t=i>0? psum[i-1]:0;
            int score=psum[k]- t;
            auto [a,b]=solve(!alice,k+1,max(m,k-i+1),psum,dp);
            if(alice && a+score>a_score){
                a_score=a+score;
                b_score=b;
            }else if(!alice && b+score>b_score){
                b_score=b+score;
                a_score=a;
            }
        }

        return dp[alice][i][m]={a_score,b_score};
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<int> prefsum(n);
        vector<vector<vector<array<int,2>>>> dp(2,vector<vector<array<int,2>>> (n,vector<array<int,2>>(2*n,{-1,-1})));
        prefsum[0]=piles[0];
        for(int i=1;i<n;i++)
            prefsum[i]=prefsum[i-1]+piles[i];
        return solve(true,0,1,prefsum,dp)[0];
    }
};