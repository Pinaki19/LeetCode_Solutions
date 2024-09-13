class Solution {
public:
    vector<int> xorQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> ans;
        for(int i=1;i<n;i++)
            nums[i]^=nums[i-1];
        for(auto& q:queries){
            int start=q[0],end=q[1];
            int t=0;
            t= start>0? nums[end]^nums[start-1]:nums[end];
            ans.push_back(t);
        }
        return ans;
    }
};