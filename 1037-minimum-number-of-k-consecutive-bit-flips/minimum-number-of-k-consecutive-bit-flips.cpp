class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int numflips=0;
        int ans=0;
        int n=nums.size();
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(v.size() && i==v.front()){
                numflips--;
                v.erase(v.begin());
            }
            if(nums[i]==0 && numflips%2==0 || (nums[i] && numflips&1 )){
                v.push_back(i+k);
                numflips++;ans++;
            }
           
        }
        if(v.empty()) return ans;
        return (v.size()==1 && v.front()==n) ? ans:-1;
    }
};