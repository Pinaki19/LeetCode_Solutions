class Solution:
    def binaryGap(self, n: int) -> int:
        ans=0
        prev1=-1
        for i in range(32):
            if ((n>>i)&1)==1:
                if prev1==-1:
                    prev1=i
                else:
                    ans=max(ans,i-prev1)
                    prev1=i
        
        return ans
