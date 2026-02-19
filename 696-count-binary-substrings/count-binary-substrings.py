class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        ans=0
        zeroCount=0
        oneCount=0
        n=len(s)
        i,j=0,0
        while i<n and j<n:
            startChar=s[i]
            curChar=s[j]
            #print(zeroCount,oneCount)
            while j<n and s[j]==curChar:
                zeroCount+=int(s[j]=='0')
                oneCount+=int(s[j]=='1')
                j+=1
                startCount=zeroCount if startChar=='0' else oneCount
                curCount= zeroCount if curChar=='0' else oneCount
                ans+=int(startCount>=curCount and min(zeroCount,oneCount)>0)
                #print(zeroCount,oneCount,ans)
            if startChar!=curChar:
                while i<n and s[i]==startChar:
                    zeroCount-=int(s[i]=='0')
                    oneCount-=int(s[i]=='1')
                    i+=1
                    #print(zeroCount,oneCount)


        return ans
        