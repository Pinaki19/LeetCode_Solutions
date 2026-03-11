class Solution:
    def bitwiseComplement(self, n: int) -> int:
        msb=0
        for i in range(31,-1,-1):
            if ((n>>i)&1)==1:
                msb=i
                break
        highest=(1<<(msb+1))-1
        return highest-n
