class Solution {
public:
    using ll=long long;
    long long maxPoints(vector<vector<int>>& points) {
        ll ans=0;

        int m=points.size();
        int n=points[0].size();

        vector<vector<ll>> dp(m,vector<ll>(n,0));

        for(int j=0;j<n;j++)
            dp[m-1][j]=points[m-1][j];
            
        for(int i=m-2;i>=0;i--){
            vector<ll> from_left(n),from_right(n);
            for(int j=0;j<n;j++){
                if(j==0){
                    from_left[0]=dp[i+1][0];
                    from_right[n-1]=dp[i+1][n-1];
                    for(int k=1;k<n;k++)
                        from_left[k]=max(from_left[k-1]-1,dp[i+1][k]);
                    for(int k=n-2;k>=0;k--)
                        from_right[k]=max(from_right[k+1]-1,dp[i+1][k]);
                }
                dp[i][j]=points[i][j]+max(from_left[j],from_right[j]);
            }
        }
        return *max_element(dp[0].begin(),dp[0].end());
    }
};