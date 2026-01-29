INF=int(1e13+7)

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        costDict=[[INF for _ in range(26)] for _ in range(26)]
        for i in range(len(original)):
            c=original[i]
            d=changed[i]
            costT=cost[i]
            cI=ord(c)-ord('a')
            dI=ord(d)-ord('a')
            costDict[cI][dI]=min(costT,costDict[cI][dI])
        #print(costDict)
        
        for i in range(26):
            costDict[i][i]=0

        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if costDict[i][k]+costDict[k][j]<costDict[i][j]:
                        costDict[i][j]=costDict[i][k]+costDict[k][j]

        total=0
        for x in range(len(source)):
            c=source[x]
            cT=target[x]
            i=ord(c)-ord('a')
            iT=ord(cT)-ord('a')
            # print(f"{c} to {cT} in {dp[i][iT]}")
            if(costDict[i][iT]==INF):
                return -1
            else:
                total+=costDict[i][iT]
        # for row in dp:
        #     for i in row:
        #         print(i if i!=INF else 'X',end="   ")
        #     print()
        return total