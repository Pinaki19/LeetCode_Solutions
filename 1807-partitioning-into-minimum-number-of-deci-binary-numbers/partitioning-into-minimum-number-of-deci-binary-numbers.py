class Solution:
    def minPartitions(self, n: str) -> int:
        ans=0
        for c in n:
            c=int(c)
            ans=max(ans,c)
        
        return ans