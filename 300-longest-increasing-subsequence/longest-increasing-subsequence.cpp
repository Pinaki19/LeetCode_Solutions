class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
           if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
           }else if(nums[i]<temp.back()){
                auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
                *it=nums[i];
           }
        }
        return temp.size();
    }
};