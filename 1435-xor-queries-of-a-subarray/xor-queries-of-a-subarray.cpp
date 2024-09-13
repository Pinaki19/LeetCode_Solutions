class Solution {
public:
    vector<int> xorQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (32,0));
        for(int i=0;i<32;i++){
            dp[0][i]= ((nums[0]>>i)&1)==1? 1:0;
        }
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1];
            int val=nums[i];
            for(int j=0;j<32;j++){
                dp[i][j]+= ((val>>j)&1)==1? 1:0;
            }
        }
        vector<int> ans;

        for(auto& q:queries){
            int start=q[0],end=q[1];
            int t=0;
            vector<int> left(32,0);
            if(start>0)
                left=dp[start-1];
            for(int i=0;i<32;i++){
                int freq=dp[end][i]-left[i];
                if(freq&1){
                    t|=(1<<i);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};