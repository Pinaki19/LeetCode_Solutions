class Solution {
public:
    int findComplement(int num) {
        int msb=31-__builtin_clz(num);
        int ans=0;

        for(int i=msb;i>=0;i--){
            if(((num>>i)&1)==0)
                ans|=(1<<i);
        }

        return ans;
    }
};