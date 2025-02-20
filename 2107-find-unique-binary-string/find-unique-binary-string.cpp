class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> v;
        for(auto& s:nums)
            v.push_back(stoi(s,0,2));
        
        sort(v.begin(),v.end());
        int ans=0;
        while(ans<v.size()){
            if(v[ans]==ans)
                ans++;
            else
                break;
        }
        bitset<16> b(ans);
        string s=b.to_string();
        while(s.size()>v.size())
            s.erase(s.begin());
        return s;
    }
};