class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        if nums[0]>=nums[1]:
            return False
        if nums[-2]>=nums[-1]:
            return False
        n=len(nums)
        p,q=1,n-2

        while p<n-1:
            if nums[p]<nums[p+1]:
                p+=1
            else:
                break
        
        if p>=n-1:
            return False
        
        while q>0:
            if nums[q-1]<nums[q]:
                q-=1
            else:
                break
        if q<=0:
            return False
        if p>=q:
            return False
        
        for i in range(p,q):
            if nums[i]<=nums[i+1]:
                return False
        
        return True