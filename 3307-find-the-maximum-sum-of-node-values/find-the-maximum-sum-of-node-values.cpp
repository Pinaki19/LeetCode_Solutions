class Solution {
public:
    long long maximumValueSum(vector<int>& v, int k, vector<vector<int>>& edges) {
        long long sum = accumulate(v.begin(), v.end(), 0LL);
        
        long long total_diff = 0;
        long long d;
        int positive = 0;
        long long min_abs_diff =INT_MAX;
        for(auto p : v){
            d = (p^k) - p;
            
            if(d > 0){
                total_diff += d;
                positive++;
            }
            min_abs_diff = min(min_abs_diff, abs(d));
        }
        if(positive % 2 == 1){
            total_diff = total_diff - min_abs_diff;
        }
        return sum + total_diff;
    }
};