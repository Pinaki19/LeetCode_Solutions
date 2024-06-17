class Solution {
public:
    bool judgeSquareSum(int c) {
        int a=0,b=sqrt(c);
        while(a<=b){
            long t=a*a*1l+b*b;
            //cout<<a<<" "<<b<<endl;
            if(t==c) return 1;
            else if(t<c) a++;
            else b--;
        }
        return 0;
    }
};