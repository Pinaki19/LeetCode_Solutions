class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        int n=nums.size(),ans=0;
        long total=0;
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            total+=nums[i];
            int rem=(total%k +k)%k;
            ans+=mp[rem].size();
            mp[rem].push_back(i);
        }

        return ans+mp[0].size();
    }
};