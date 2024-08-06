class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        int freq[26]={0};
        for(char c:word){
            freq[c-'a']++;
        }
        auto x=[&freq](char a,char b){
            if(freq[a-'a']==freq[b-'a'])
                return a<b;
            return freq[a-'a']>freq[b-'a'];
        };
        sort(word.begin(),word.end(),x);
        char prev='1';
        int cur=7;
        for(char c:word){
            if(c!=prev){
                prev=c;
                cur++;
            }
            ans+=cur/8;
        }
        
        return ans;
    }
};