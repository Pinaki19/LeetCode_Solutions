class Solution:
    def reverseBits(self, n: int) -> int:
        nStr=f"{str(bin(n))[2:]:0>32}"
        revNStr=nStr[::-1]
        return int(revNStr,2)