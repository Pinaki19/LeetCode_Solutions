class Solution {
    final int MOD=(int)1e9+7;
    int dp[][][];
    int solve(int x,int y,String[] pizza,int numCuts){
        int c;
        if(dp[x][y][numCuts]>=0) return dp[x][y][numCuts];
        if(numCuts==0){
            for(int i=x;i<pizza.length;i++)
                for(int j=y;j<pizza[i].length();j++){
                    if(pizza[i].charAt(j)=='A')
                        return 1;
                }
            return 0;
        }
        
        long ans=0;
        c=0;
        for(int j=x;j<pizza.length-1;j++){
            for(int k=y;k<pizza[j].length();k++)
                if(pizza[j].charAt(k)=='A')
                    c++;
            if(c>0){
                ans+=solve(j+1,y,pizza,numCuts-1)%MOD;
                ans%=MOD;
            }
        }
        c=0;
       for(int j=y;j<pizza[x].length()-1;j++){
            
            for(int k=x;k<pizza.length;k++){
                if(pizza[k].charAt(j)=='A')
                    c++;
            }
            if(c>0){
                ans+=solve(x,j+1,pizza,numCuts-1)%MOD;
                ans%=MOD;
            }
       }
        return dp[x][y][numCuts]=(int)ans;
    }
    public int ways(String[] pizza, int k) {
        int m=pizza.length;
        int n=pizza[0].length();
        dp=new int[m][n][k];
        for(int[][] temp:dp)
            for(int[] t:temp)
                Arrays.fill(t,-1);
        return solve(0,0,pizza,k-1)%MOD;
    }
}