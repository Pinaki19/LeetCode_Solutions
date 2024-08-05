class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        ios_base::sync_with_stdio(0);
        string ans="";
        map<string,int> mp;
        for(auto s:arr){
            mp[s]++;
        }
        for(auto &s:arr){
            if(mp[s]==1){
                k--;
                if(k==0){
                    ans=s;
                    break;
                }
            }
        }
        return ans;
    }
};