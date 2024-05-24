class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int freqMax[]=new int[26];
        Arrays.fill(freqMax,0);
        for(char c:letters)
            freqMax[c-'a']++;
        int n=words.length;
        int scores[]=new int[n];
        int freqs[][]= new int[n][26];
        for(int i=0;i<n;i++){
            Arrays.fill(freqs[i],0);
            String s=words[i];
            int cur=0;
            for(int j=0;j<s.length();j++){
                char c=s.charAt(j);
                freqs[i][c-'a']++;
                if(freqs[i][c-'a']>freqMax[c-'a']){
                    cur=Integer.MIN_VALUE;
                    break;
                }else
                    cur+=score[c-'a'];
            }
            scores[i]=cur;
        }
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            int curFreq[]=new int[26];
            Arrays.fill(curFreq,0);
            int cur=0;
            Inner:
            for(int j=0;j<n;j++){
                if(((i>>j)&1)==1){
                    for(int k=0;k<26;k++){
                        curFreq[k]+=freqs[j][k];
                        if(curFreq[k]>freqMax[k]){
                            cur=-1;
                            break Inner;
                        }
                    }
                    cur+=scores[j];
                }
            }
            ans=Math.max(ans,cur);
        }
        return ans;
    }
}