class Solution {
public:
    using ll=long long;
    const ll NINF=-(ll)1e10;
    int dp[101][101][101];
    ll solve(int row,int c1,int c2,auto& bv,int c,auto& dp){
        if(c==3) return 0;
        if(row>=bv.size()) return NINF;
        if(c2!=-1 && dp[row][c1][c2]!=-1) return  dp[row][c1][c2];
        ll ans=solve(row+1,c1,c2,bv,c,dp);
        for(auto [val,col]:bv[row]){
            if(col==c1 || col==c2) continue;
            if(c1==-1)
                ans=max(ans,val+solve(row+1,col,-1,bv,c+1,dp));
            else if(c2==-1)
                ans=max(ans,val+solve(row+1,c1,col,bv,c+1,dp));
            else
                ans=max(ans,val+solve(row+1,c1,c2,bv,c+1,dp));
        }
        if(c2!=-1)
            return dp[row][c1][c2]=ans;
        return ans;
    }
    
    long long maximumValueSum(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<pair<int,int>>> board_vals(m);
        for(int i=0;i<m;i++){
            priority_queue<pair<int,int>> pq;
            for(int j=0;j<n;j++)
                pq.push({board[i][j],j});
            int c=0;
            while(pq.size() && c<3){
                pair<int,int> t=pq.top();
                pq.pop();
                c++;
                board_vals[i].push_back(t);
            }
        }

        memset(dp,-1,sizeof(dp));
        return solve(0,-1,-1,board_vals,0,dp);
    }
};