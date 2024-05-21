class Solution {
public:
   
    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        vector<vector<int>> result;
        vector<int> temp;
        for(int i=0;i<(1<<nums.size());i++){
            for(int j=0;j<nums.size();j++){
                if((i>>j)&1)
                    temp.push_back(nums[j]);
            }
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};