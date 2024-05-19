class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        for(int &i:nums){
            i%=2;
        }
        
        vector<int> temp(nums.size());
        temp[0]=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) temp[i]=temp[i-1]+1;
            else temp[i]=temp[i-1];
        }
        
        vector<bool> ans;
        for(auto q:queries){
            int s=q[0],e=q[1];
            if(s==e){
                ans.push_back(true);
            }else{
                int stval=temp[s];
                int endval=temp[e];
                if(endval-stval==0){
                    ans.push_back(true);
                }else{
                    ans.push_back(false);
                }
                
            }
        }
        return ans;
    }
};