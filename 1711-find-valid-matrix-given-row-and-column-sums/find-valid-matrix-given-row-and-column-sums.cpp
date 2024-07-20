class Solution {
public:
    int m,n;
    void solve(int x,int y,auto& rowSum,auto& colSum,auto& ans,bool& solved){
         if(x==m){
                for(int i=0;i<m;i++)
                    if(rowSum[i])
                        return;
                for(int j=0;j<n;j++)
                    if(colSum[j]) 
                        return;
                solved=true;
                return;
            }
            if(solved) return;
            int nx= y==n-1? x+1:x;
            int ny= y==n-1? 0:y+1;

            for(int i=min(rowSum[x],colSum[y]);i>=0;i--){
                rowSum[x]-=i;
                colSum[y]-=i;
                ans[x][y]=i;
                solve(nx,ny,rowSum,colSum,ans,solved);
                if(solved) return;
                rowSum[x]+=i;
                colSum[y]+=i;
            }
    }
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        m=rowSum.size();
        n=colSum.size();
        bool solved=false;
        vector<vector<int>> ans(m,vector<int>(n,0));

        solve(0,0,rowSum,colSum,ans,solved);
        return ans;
    }
};