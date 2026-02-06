import bisect
k=0
def getMinDel(nums,low,high,val,minVal):
    if minVal:
        maxKeepL=val*k
        keepLInd=bisect.bisect_right(nums,maxKeepL,lo=low,hi=high)
        return len(nums)-keepLInd
    else:
        minKeepH=ceil(val/k)
        keepHInd=bisect.bisect_left(nums,minKeepH,lo=low,hi=high)
        return keepHInd
    return 0

class Solution:
    def minRemoval(self, nums: List[int], K: int) -> int:
        nums.sort()
        global k
        k=K
        #print(nums)
        minDel=len(nums)-1
        for i in range(0,len(nums)//2):
            minDel=min(minDel,i+getMinDel(nums,i,len(nums),nums[i],True))

        for i in range(len(nums)-1,len(nums)//2,-1):
            numDel=len(nums)-1-i
            minDel=min(minDel,numDel+getMinDel(nums,0,i+1,nums[i],False))
        return minDel