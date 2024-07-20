class Solution {
public:
    int m,n;
    void solve(int x,int y,auto& rowSum,auto& colSum,auto& ans){
        if(x==m)
            return;
        int nx= y==n-1? x+1:x;
        int ny= y==n-1? 0:y+1;
        int i=min(rowSum[x],colSum[y]);
        rowSum[x]-=i;
        colSum[y]-=i;
        ans[x][y]=i;
        solve(nx,ny,rowSum,colSum,ans);
    }
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        m=rowSum.size();
        n=colSum.size();
        vector<vector<int>> ans(m,vector<int>(n,0));

        solve(0,0,rowSum,colSum,ans);
        return ans;
    }
};