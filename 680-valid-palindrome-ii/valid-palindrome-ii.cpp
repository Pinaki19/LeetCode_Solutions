class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r && s[l]==s[r]){
            l++;
            r--;
        }
        if(l>=r) return true;
        int nextL=l+1;
        int prevR=r-1;
        while(nextL<r && s[nextL]==s[r]){
            nextL++;
            r--;
        }
        while(l<prevR && s[l]==s[prevR]){
            l++;
            prevR--;
        }
        return nextL>=r || l>=prevR;
    }
};