class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total_req=accumulate(chalk.begin(),chalk.end(),0ll);
        k%=total_req;
        int n=chalk.size();
        vector<long long> pref(n);
        pref[0]=chalk[0];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+chalk[i];
        
        int ans=0;
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(pref[mid]>k){
                ans=mid;
                r=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};