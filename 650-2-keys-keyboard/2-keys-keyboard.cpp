class Solution {
private:
    static const int lim=1001;
    bitset<lim> bs;
    vector<int> primes;
    void sieve(){
        bs.set();
        bs[0]=0;
        bs[1]=0;
        primes.push_back(2);
        for(int j=4;j<lim;j+=2)
            bs[j]=0;
        for(int i=3;i<lim;i+=2){
            if(bs[i]){
                primes.push_back(i);
                for(int j=i*i;j<lim;j+=i)
                    bs[j]=0;
            }
        }
    }
public:
    Solution(){
        sieve();
    }
    int minSteps(int n) {
        int c=0;
        int l=0;
        while(n>1){
            if(primes[l]>n) break;
            while(n%primes[l]==0){
                c+=primes[l];
                n/=primes[l];
            }
            l++;
        }
        return c;
    }
};