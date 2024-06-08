class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        set<int> s;
        long tot=0;
        int numzeroes=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                numzeroes++;
                if(numzeroes>1) return true;
                continue;
            }
            tot+=nums[i];
            int rem=tot%k;
            if((s.find(rem)!=s.end()||tot%k==0)&& i>0) return true;
            s.insert(rem);
            numzeroes=0;
        }
        return false;
    }
};