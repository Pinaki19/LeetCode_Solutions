class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> xocc;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x)
                xocc.push_back(i);
        }
        vector<int> ans;
        for(int i:queries){
            if(i>xocc.size())
                ans.push_back(-1);
            else
                ans.push_back(xocc[i-1]);
        }
        return ans;
    }
};