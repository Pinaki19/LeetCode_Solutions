class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int maxVal=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=maxVal) continue;
            int r=i+1;
            while(r<n && nums[r]==nums[i])
                r++;
            ans=max(ans,r-i);
            i=r;
        }

        return ans;
    }
};