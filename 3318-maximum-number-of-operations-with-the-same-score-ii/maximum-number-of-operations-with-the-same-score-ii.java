class Solution {
    public int solve(int l,int r,int[] nums,int[][] dp,int sum){
        if(l>=r) return 0;
        if(dp[l][r]>=0) return dp[l][r];
        int ans=0;
        if(nums[l]+nums[l+1]==sum)
            ans=1+solve(l+2,r,nums,dp,sum);
        if(nums[r]+nums[r-1]==sum)
            ans=Math.max(ans,1+solve(l,r-2,nums,dp,sum));
        if(nums[l]+nums[r]==sum)
            ans=Math.max(ans,1+solve(l+1,r-1,nums,dp,sum));
        return dp[l][r]=ans;
    }
    public int maxOperations(int[] nums) {
        int n=nums.length;
        int[][] dp=new int[n][n];
        
        for(int[] t:dp)
            Arrays.fill(t,-1);
        int ans=0;
        ans=solve(0,n-1,nums,dp,nums[0]+nums[1]);
        for(int[] t:dp)
            Arrays.fill(t,-1);
        ans=Math.max(ans,solve(0,n-1,nums,dp,nums[n-2]+nums[n-1]));
        for(int[] t:dp)
            Arrays.fill(t,-1);
        ans=Math.max(ans,solve(0,n-1,nums,dp,nums[0]+nums[n-1]));
        return ans;
    }
}