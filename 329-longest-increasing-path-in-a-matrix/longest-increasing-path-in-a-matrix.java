class Solution {
    int[][] dir={{0,1},{0,-1},{1,0},{-1,0}};
    boolean isvalid(int i,int j,int [][] m,int val){
        return i>=0 && i<m.length && j>=0 && j<m[0].length && m[i][j]>val;
    }
    int maxPath(int i,int j,int[][] m,int[][] dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        int v=m[i][j];
        m[i][j]=-1;
        for(int[] d:dir){
            int dx=d[0],dy=d[1];
            int nx=i+dx,ny=j+dy;
            if(isvalid(nx,ny,m,v)){
                ans=Math.max(ans,maxPath(nx,ny,m,dp));
            }
        }
        m[i][j]=v;
        return dp[i][j]=1+ans;
    }
    public int longestIncreasingPath(int[][] matrix) {
        int m=matrix.length,n=matrix[0].length;
        int[][] dp=new int[m][n];
        for(int i=0;i<m;i++)
            Arrays.fill(dp[i],-1);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=Math.max(ans,maxPath(i,j,matrix,dp));
            }
        }
        return ans;
    }
}