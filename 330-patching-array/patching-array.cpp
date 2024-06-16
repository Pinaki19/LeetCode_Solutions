class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans=0;
        int i=0;
        long cur=1;

        while(cur<=n){
            if(i<nums.size() && nums[i]<=cur){
                cur+=nums[i++];
            }else{
                cur+=cur;
                ans++;
            }
        }

        return ans;
    }
};