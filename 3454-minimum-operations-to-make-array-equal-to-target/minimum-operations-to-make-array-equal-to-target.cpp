using ll=long long;
class Solution {
public:
  
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> diffs(n);

        for (int i = 0; i < n; ++i) {
            diffs[i] = nums[i] - target[i];
        }
        ll ans=0;
        ll prev=0;
        for(int i:diffs){
            cout<<i<<" ";
            if(i<0){
                if(i<prev)
                    ans+=-i+min(0ll,prev);
            }else if(i>0){
                if(i>prev)
                    ans+=i-max(0ll,prev);
            }
            prev=i;
        }
        return ans;
    }
};