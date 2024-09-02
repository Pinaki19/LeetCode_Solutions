class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total_req=accumulate(chalk.begin(),chalk.end(),0ll);
        k%=total_req;
        for(int i=0;i<chalk.size();i++){
            if(k<chalk[i])
                return i;
            k-=chalk[i];
        }
        return 0;
    }
};