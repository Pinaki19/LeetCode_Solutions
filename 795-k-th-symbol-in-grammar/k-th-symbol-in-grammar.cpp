class Solution {
public:
    int kthGrammar(int n, int k) {
        auto get_expansion=[](int i)->pair<int,int>{
            if(i==0) return {0,1};
            return {1,0};
        };
        function<pair<int,int>(int)> solve=[&](int k)->pair<int,int>{
            if(k==0) return {0,1};
            auto [f,s]=solve(k/2);
            if(k&1) return get_expansion(s);
            return get_expansion(f);
        };
        auto [f,s]=solve((k-1)/2);
        if(k&1)
            return f;
        return s;
    }
};