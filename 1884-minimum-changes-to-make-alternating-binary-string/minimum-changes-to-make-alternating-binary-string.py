class Solution:
    def minOperations(self, s: str) -> int:
        total=len(s)
        n1=0
        n2=1
        prev=s[0]
        prevOther= '1' if prev=='0' else '0'
        for i in range(1,total):
            c=s[i]
            if c==prev:
                n1+=1
                prev='1' if prev=='0' else '0'
            else:
                prev=c
            if c==prevOther:
                n2+=1
                prevOther='1' if prev=='0' else '0'
            else:
                prevOther=c
        
        return min(n1,n2)

