class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        primes={2,3,5,7,11,13,17,19,23,29,31,37}
        ans=0
        for i in range(left,right+1):
            count=0
            for bit in range(32):
                if ((i>>bit)&1)==1:
                    count+=1
            if count in primes:
                ans+=1

        return ans
