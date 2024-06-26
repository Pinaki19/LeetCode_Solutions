class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        ios_base::sync_with_stdio(0);
        vector<string> ans;
        int cnt[26],maxCnt[26];
        fill(maxCnt,maxCnt+26,99999);

        for(int i=0;i<words.size();i++){
            fill(cnt,cnt+26,0);
            for(char c:words[i]){
                int t=c-'a';
                cnt[t]=min(cnt[t]+1,maxCnt[t]);
            }
            
            for(int p=0;p<26;p++){
                maxCnt[p]=min(maxCnt[p],cnt[p]);
            }
        }

        for(int i=0;i<26;i++){
            string s="";
            s+='a'+i;
            for(int j=0;j<maxCnt[i];j++)
                ans.push_back(s);
        }
        return ans;
    }
};