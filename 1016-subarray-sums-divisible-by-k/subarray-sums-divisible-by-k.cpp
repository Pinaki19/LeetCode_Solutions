class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),ans=0;
        long total=0;
        map<int,vector<int>> mp;
        auto getRem=[&k](int n)->int{
            int rem=n%k;
            int canadd=0;
            if(rem<0)
                canadd=ceil((float)(abs(n))/k);
            return rem<0? n+canadd*k:rem;
        };
        for(int i=0;i<n;i++){
            total+=nums[i];
            int rem=getRem(total);
            //cout<<nums[i]<<" "<<rem<<' '<<total<<endl;
            ans+=mp[rem].size();
            mp[rem].push_back(i);
        }

        return ans+mp[0].size();
    }
};