class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int diff=nums.back()-nums.front();
        int l=0,r=diff;
        int ans=0;

        auto get_pos=[&nums](int i,int val)->int{
            int n=nums.size();
            int l=i,r=n-1;
            int ans=nums.size()-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]<=val){
                    ans=mid;
                    l=mid+1;
                }else
                    r=mid-1;
            }

            return ans;
        };

        while(l<=r){
            int mid=l+(r-l)/2;
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                int diff= get_pos(i,nums[i]+mid)-i;
                cnt+=diff;
            }
            if(cnt>=k){
                ans=mid;
                r=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};