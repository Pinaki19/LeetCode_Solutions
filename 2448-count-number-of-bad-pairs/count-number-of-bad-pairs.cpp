class Solution {
public:
    using ll=long long;
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        ll total=(n*1ll*(n-1))/2;
        for(int i=0;i<n;i++){
            nums[i]-=i;
            mp[nums[i]]+=1;
            total-=mp[nums[i]]-1;
        }

        return total;
    }
};