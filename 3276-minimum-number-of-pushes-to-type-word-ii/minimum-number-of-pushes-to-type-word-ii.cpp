class Solution {
public:
    int minimumPushes(string word) {
        int freq[26]={0};
        for(char c:word){
            freq[c-'a']++;
        }
        auto x=[&freq](char a,char b){
            if(freq[a-'a']==freq[b-'a'])
                return a<b;
            return freq[a-'a']>freq[b-'a'];
        };
        int cur=1;
        int ans=0;
        map<int,int,decltype(x)> mp(x);
        for(char c:word){
            mp[c]++;
        }
        int cnt=7;
        for(auto [k,v]:mp){
            cnt++;
            cur=cnt/8;
            ans+=v*cur;
        }

        return ans;
    }
};