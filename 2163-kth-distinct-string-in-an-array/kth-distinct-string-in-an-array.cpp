class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string ans="";
        int cur=0;
        multiset<string> ms(arr.begin(),arr.end());
        for(auto& s:arr){
            if(ms.count(s)==1){
                cur++;
                if(cur==k){
                    ans=s;
                    break;
                }
            }
        }

        return ans;
    }
};