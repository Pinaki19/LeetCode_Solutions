class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n=len(nums)
        ans=0
        for i in range(n):
            evens=defaultdict(int)
            odds=defaultdict(int)
            for j in range(i,n):
                if((nums[j]&1)==1):
                    odds[nums[j]]+=1
                else:
                    evens[nums[j]]+=1

                if len(evens)==len(odds):
                    ans=max(ans,j-i+1)
            
        return ans