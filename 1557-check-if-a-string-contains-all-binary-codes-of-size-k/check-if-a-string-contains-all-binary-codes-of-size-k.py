class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        seen=set()
        l,r=0,k
        n=len(s)
        if n<k:
            return False
        cur=s[:k]
        seen.add(cur)
        req=(1<<k)
        while r<n and len(seen)<req:
            cur=cur[1:]
            cur+=s[r]
            seen.add(cur)

            l+=1
            r+=1

        return len(seen)==req



        
