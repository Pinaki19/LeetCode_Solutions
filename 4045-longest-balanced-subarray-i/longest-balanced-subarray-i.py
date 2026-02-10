class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n=len(nums)
        ans=0
        evens=set()
        odds=set()
        for i in range(n):
            
            for j in range(i,n):
                if((nums[j]&1)==1):
                    odds.add(nums[j])
                else:
                    evens.add(nums[j])
                if len(evens)==len(odds):
                    ans=max(ans,j-i+1)
            odds.clear()
            evens.clear()
        return ans