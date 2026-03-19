def translate(c):
    return 0 if c=='X' else 1 if c=='Y' else 2

def process(i,j,p):
    i1,i2,i3=p[i-1][j]
    i4,i5,i6=p[i][j-1]
    x1,x2,x3=p[i-1][j-1]
    return [i1+i4-x1,i2+i5-x2,i3+i6-x3]
class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m,n=len(grid),len(grid[0])
        base=[0,0,0]
        prefSum=[[base.copy() for _ in range(n)] for _ in range(m)]
        ans=0
        for i in range(m):
            for j in range(n):
                if i==0 and j==0:
                    prefSum[i][j][translate(grid[i][j])]+=1
                elif i==0:
                    prefSum[i][j]=prefSum[i][j-1].copy()
                    prefSum[i][j][translate(grid[i][j])]+=1
                elif j==0:
                    prefSum[i][j]=prefSum[i-1][j].copy()
                    prefSum[i][j][translate(grid[i][j])]+=1
                else:
                    prefSum[i][j]=process(i,j,prefSum)
                    prefSum[i][j][translate(grid[i][j])]+=1
                
                if prefSum[i][j][0]>0 and prefSum[i][j][0]==prefSum[i][j][1]:
                    ans+=1
        
        return ans