using ll=long long;
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        stack<int> st;
        unordered_map<int,int> mp;
        ll ans=0;
        while(r<n){
            ans++;
            while(st.size() && nums[r]>st.top()){
                mp[st.top()]=0;
                st.pop();
            } 
            st.push(nums[r]);
            ans+=mp[st.top()];
            mp[nums[r]]++;
            r++;
        }
        return ans;
    }
};