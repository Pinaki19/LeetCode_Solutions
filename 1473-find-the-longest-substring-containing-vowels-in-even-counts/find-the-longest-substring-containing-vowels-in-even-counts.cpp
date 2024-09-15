class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char,int> mp;
        mp['a']=0;
        mp['e']=1;
        mp['i']=2;
        mp['o']=3;
        mp['u']=4;
        auto isVowel=[&](char c){
            return mp.find(c)!=mp.end();
        };
        vector<int> seen(50,-1);
        int curmask=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isVowel(c)){
                int ind=mp[c];
                curmask^=(1<<ind);
            }
            if(curmask==0) 
                ans=max(ans,i+1);
            else if(seen[curmask]==-1)
                seen[curmask]=i;
            else 
                ans=max(ans,i-seen[curmask]);
        }
        return ans;
    }
};