class Solution {
public:
    int specialArray(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       for(int i=1;i<1000;i++){
            auto pos=lower_bound(nums.begin(),nums.end(),i);
            if(pos==nums.end()) break;
            if(distance(pos,nums.end())==i) return i;
       }
       return -1;
    }
};