
class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        ln=len(nums)
        result=[0 for _ in range(ln)]
        for i,n in enumerate(nums):
            if n<0:
                val=abs(n)
                newInd= (i-val)%ln if (i-val>=0) else (ln-((val-i)%ln))%ln
                result[i]=nums[newInd]
            elif n>0:
                newInd=(i+n)%ln
                result[i]=nums[newInd]

        return result