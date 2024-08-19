class Solution {
public:
    string longestPalindrome(string s) {
        int L=0,R=0;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            int r=i+1,l=i-1;
            while(r<n && s[r]==s[i])
                r++;
            while(l>=0 && r<n && s[l]==s[r])
                l--,r++;
            int len=r-l-1;
            if(len>(R-L+1)){
                R=r-1;
                L=l+1;
            }
        }
        string ans=s.substr(L,R-L+1);
        return ans;
    }
};