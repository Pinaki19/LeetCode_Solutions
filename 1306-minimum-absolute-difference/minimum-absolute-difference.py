class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        minDiff=arr[1]-arr[0]
        ans=[[arr[0],arr[1]]]
        for i in range(1,len(arr)-1):
            diff=arr[i+1]-arr[i]
            if(diff<=minDiff):
                if(diff<minDiff):
                    minDiff=diff
                    ans.clear()
                ans.append([arr[i],arr[i+1]])
            
        return ans