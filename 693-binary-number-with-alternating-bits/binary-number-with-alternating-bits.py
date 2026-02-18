class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        prevSet=bool(n&1)
        for i in range(1,32):
            if (1<<i)>n:
                break
            if ((n>>i)&1)==1:
                if prevSet:
                    return False
                else:
                    prevSet=True
            else:
                if not prevSet:
                    return False
                else:
                    prevSet=False


        return True