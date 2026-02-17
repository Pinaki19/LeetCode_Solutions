class Solution:
    def __init__(self):
        self.ans=set()
    def validHours(self,n,curVal,numSet,startBit):
        if n>=9 or numSet>=n and n>0:
            return
        
        for i in range(startBit,4):
            if (curVal>>i)&1==1:
                continue
            else:
                tVal=curVal|(1<<i)
                if tVal>=12:
                    continue
                else:
                    mins=[]
                    self.validMins(n-(numSet+1),0,0,0,mins)
                    for _min in mins:
                        self.ans.add(f"{tVal}:{_min}")
                    self.validHours(n,tVal,numSet+1,i+1)
        allMins=[]
        self.validMins(n-numSet,0,0,0,allMins)
        for _min in allMins:
            self.ans.add(f"{curVal}:{_min}")
    def validMins(self,n,curVal,numSet,startBit,al):
        if n>6:
            return
        if n==0:
            al.append('00')
            return
        for i in range(startBit,6):
            if (curVal>>i)&1==1:
                continue
            else:
                tVal=curVal|(1<<i)
                if tVal>=60:
                    continue
                elif(numSet+1==n):
                    al.append(f'{tVal:0>2}')
                else:
                    self.validMins(n,tVal,numSet+1,i+1,al)
        
    def fn(self,x):
        hour,_min=x.split(':')
        return int(hour),int(_min)

    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        self.ans.clear()
        self.validHours(turnedOn,0,0,0)
        ans=list(self.ans)
        ans.sort(key= self.fn)
        return ans