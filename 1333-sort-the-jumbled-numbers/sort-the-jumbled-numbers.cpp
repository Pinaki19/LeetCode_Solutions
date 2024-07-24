class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> nmap;
        auto convert=[&mapping](int i)->int{
            string s=to_string(i);
            int num=0;
            for(char c:s){
                num=num*10+mapping[c-'0'];
            }
            return num;
        };

        for(int i=0;i<nums.size();i++)
            nmap.push_back({convert(nums[i]),i});
        sort(nmap.begin(),nmap.end());

        vector<int> ans;
        for(auto [_,ind]:nmap){
            ans.push_back(nums[ind]);
        }
           
        return ans;
    }
};