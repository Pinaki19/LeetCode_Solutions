class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        if len(s)<=2:
            return s
        l=[]
        balance=0
        start=0
        n=len(s)
        for i in range(n):
            c=s[i]
            if c=='1':balance+=1
            else:balance-=1
            if balance==0:
                temp='1'+self.makeLargestSpecial(s[start+1:i])+'0'
                l.append(temp)
                start=i+1
                print(temp)
                
        print(l)
        l.sort(reverse=True) 
        print(l)
        return ''.join(l)