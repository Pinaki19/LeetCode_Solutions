class Solution:
    def check(self,letters):
        i=0
        while i<26:
            if letters[i]>0:
                break
            else:
                i+=1
        exp=letters[i]
        while i<26:
            if letters[i]>0 and letters[i]!=exp:
                return False
            i+=1
        return True
    def longestBalanced(self, s: str) -> int:
        letters=[0 for _ in range(26)]
        ans=0
        n=len(s)
        for i in range(n):
            for j in range(i,n):
                c=s[j]
                iC=ord(c)-ord('a')
                letters[iC]+=1
                if self.check(letters):
                    ans=max(ans,j-i+1)
            letters=[0 for _ in range(26)]
        return ans