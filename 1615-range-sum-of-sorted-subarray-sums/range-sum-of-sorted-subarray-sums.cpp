class Solution {
public:
    const int MOD=(int)1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long> all;
        vector<long> psum(n);
        psum[0]=nums[0];
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+nums[i];
        }

        for(int i=0;i<n;i++){
            long left= i==0? 0:psum[i-1];
            for(int j=i;j<n;j++)
                all.push_back(psum[j]-left);
        }

        sort(all.begin(),all.end());
        left--;
        right--;
        long ans=0;
        for(int i=left;i<=right;i++){
            ans+=all[i];
            ans%=MOD;
        }
        return ans;
    }
};