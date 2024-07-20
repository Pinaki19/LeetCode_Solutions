class Solution {
public:
    int minimumLength(string s) {
        int ans;
        int freq[26]={0};
        for(char c:s){
            int t=c-'a';
            freq[t]++;
            if(freq[t]==3)
                freq[t]=1;
        }
        return accumulate(freq,freq+26,0);
    }
};