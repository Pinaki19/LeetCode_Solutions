class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0,cur;
        for(int i=1;i<(1<<n);i++){
            cur=0;
            for(int j=0;j<nums.size();j++){
                if((i>>j)&1)
                    cur^=nums[j];
            }
            ans+=cur;
        }
        return ans;
    }
};