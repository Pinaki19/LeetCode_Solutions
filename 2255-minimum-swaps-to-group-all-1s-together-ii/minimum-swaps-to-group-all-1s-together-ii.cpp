class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //0,1,1,1,0,0,1,1,0 || 0,1,1,1,0,0,1,1,0
        int n=nums.size();
        vector<int> temp_nums(nums.begin(),nums.end());
        int cnt=0;
        for(int i:nums)
            temp_nums.push_back(i),cnt+= i==1;
        
        int l=0,r=0;
        int c=0;
        int ans=INT_MAX;
        while(l<n){
            c+= temp_nums[r]==1;
            while(r-l+1>cnt){
                c-= temp_nums[l]==1;
                l++;
            }
            ans=min(ans,cnt-c);
            r++;
        }

        return ans;
    }
};