class Solution {
public:
    int solve(auto& nums,int k){
        int ans=0;  
        int l=0,r=0;
        int n=nums.size();
        int oddcnt=0;
        while(r<n){
            if(nums[r]&1) oddcnt++;
            while(oddcnt>k){
                if(nums[l]&1) oddcnt--;
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);   
    }
};