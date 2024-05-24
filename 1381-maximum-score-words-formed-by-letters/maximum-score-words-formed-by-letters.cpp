class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int freqMax[26]={0};
        for(char c:letters)
            freqMax[c-'a']++;
        int n=words.size();
        int scores[n];
        int freqs[n][26];
        for(int i=0;i<n;i++){
            fill(freqs[i],freqs[i]+26,0);
            string s=words[i];
            int cur=0;
            for(char c:s){
                freqs[i][c-'a']++;
                if(freqs[i][c-'a']>freqMax[c-'a']){
                    cur=0;
                    break;
                }else
                    cur+=score[c-'a'];
            }
            scores[i]=cur;
        }
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            int curFreq[26]={0};
            int cur=0;
            for(int j=0;j<n && cur>=0;j++){
                if((i>>j)&1){
                    for(int k=0;k<26;k++){
                        curFreq[k]+=freqs[j][k];
                        if(curFreq[k]>freqMax[k]){
                            cur=INT_MIN;
                            break;
                        }
                    }
                    cur+=scores[j];
                }
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};