INF=int(1e9+7)

class Solution:
    def minimumDeletions(self, s: str) -> int:
        n=len(s)
        aCnt=[0 for _ in range(n)]
        bCnt=aCnt.copy()
        c=0
        for i in range(0,n):
            bCnt[i]=c
            if s[i]=='b':
                c+=1
        c=0
        for i in range(n-1,-1,-1):
            aCnt[i]=c
            if s[i]=='a':
                c+=1
        ans=INF
        for i in range(n):
            ans=min(ans,aCnt[i]+bCnt[i])
        return ans