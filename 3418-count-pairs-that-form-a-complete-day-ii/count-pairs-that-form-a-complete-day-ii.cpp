#define ll long long
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& h) {
        int n=h.size();
        unordered_map<int,int> mp;
        ll ans=0;
        for(int i=0;i<n;i++){
            int t=(24-h[i]%24)%24;
            ans+=mp[t];
            mp[h[i]%24]++;
        }
        return ans;
    }
};