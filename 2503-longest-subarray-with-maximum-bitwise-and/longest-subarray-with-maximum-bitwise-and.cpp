class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int maxVal=*max_element(nums.begin(),nums.end());
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]||nums[i]!=maxVal) continue;
            int r=i+1;
            visited[i]=true;
            int curAnd=nums[i];
            while(r<n && nums[r]==nums[i]){
                visited[r++]=true;
            }
            ans=max(ans,r-i);
        }

        return ans;
    }
};