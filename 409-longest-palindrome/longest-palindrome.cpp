class Solution {
public:
    int longestPalindrome(string s) {
        int freq[100]={0};
        for(char c:s){
            freq[c-'A']++;
        }

        long ans=0;
        int odd=0;
        for(int i=0;i<100;i++){
            if((freq[i]&1)==0) ans+=freq[i];
            else{ 
                ans+=freq[i]-1;
                odd=1;
            }
        }
        return ans+odd;
    }
};