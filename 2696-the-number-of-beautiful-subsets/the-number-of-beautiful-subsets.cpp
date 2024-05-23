class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans=0;
        bool ex[1001]={0};
        bool b=1;
        for(int i=0;i<(1<<nums.size());i++){
            b=1;
            for(int j=0;j<nums.size();j++){
                if((i>>j)&1){
                    ex[nums[j]]=1;
                    if(nums[j]-k>=0 && ex[nums[j]-k]){
                        b=0;break;
                    }
                    if(nums[j]+k<=1000 && ex[nums[j]+k]){
                        b=0;break;
                    }
                }
            }
            if(b) ans++;
            for(int j=0;j<nums.size();j++)
                if((i>>j)&1)
                    ex[nums[j]]=0;
        }
        return ans-1;
    }
};