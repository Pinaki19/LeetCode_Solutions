class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        set<unsigned long> s;
        s.insert(1);
        for(int i=1;i<n;i++){
            unsigned int curMin=*s.begin();
            s.erase(s.begin());
            for(int k:{2,3,5})
                s.insert(curMin*1ul*k);
        }
        
        return static_cast<unsigned>(*s.begin());
    }
};