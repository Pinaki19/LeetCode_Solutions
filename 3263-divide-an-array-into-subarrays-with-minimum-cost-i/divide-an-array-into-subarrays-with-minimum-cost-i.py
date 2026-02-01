class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        ans=nums[0]
        INF=int(1e9+7)
        fMin=sMin=INF
        for i in range(1,len(nums)):
            val=nums[i]
            if val<fMin:
                sMin=fMin
                fMin=val
            elif val<sMin:
                sMin=val
        print(ans,fMin,sMin)
        return ans+fMin+sMin
        