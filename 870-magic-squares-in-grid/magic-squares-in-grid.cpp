class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;

        auto check=[](auto& rs,auto& cs,int ds1,int ds2,int t){
            bool equal=(rs[0]==rs[1]);
            equal&=(rs[1]==rs[2]);
            equal&=(rs[0]==cs[0]);
            equal&=(cs[0]==cs[1]);
            equal&=(cs[1]==cs[2]);
            equal&=(cs[0]==ds1);
            equal&=(ds1==ds2);
            equal&=((t&1)==0);
            for(int i=1;i<=9;i++){
                equal&=((t>>i)&1);
            }
            return equal;
        };
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                int rowSum[3]={0};
                int colSum[3]={0};
                int ds1=0,ds2=0;
                int t=0;
                for(int k=i;k<i+3;k++){
                    for(int p=j;p<j+3;p++){
                        rowSum[k-i]+=grid[k][p];
                        colSum[p-j]+=grid[k][p];
                        t|=(1<<grid[k][p]);
                    }
                }
                ds1+=grid[i][j]+grid[i+2][j+2]+grid[i+1][j+1];
                ds2+=grid[i+2][j]+grid[i][j+2]+grid[i+1][j+1];
                if(check(rowSum,colSum,ds1,ds2,t))
                    ans++;
            }
        }
        return ans;
    }
};