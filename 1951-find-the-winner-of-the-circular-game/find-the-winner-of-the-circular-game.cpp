class Solution {
public:
    int findTheWinner(int n, int k) {
        k--;
        int cur=0,t;
        vector<int> v(n);
        iota(v.begin(),v.end(),1);
        while(v.size()>1){
            t=k%v.size();
            cur+=t;
            cur%=v.size();
            v.erase(v.begin()+cur);
        }
        return *v.begin();
    }
};