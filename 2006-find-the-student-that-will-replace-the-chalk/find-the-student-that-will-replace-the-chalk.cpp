class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long long> pref(n);
        pref[0]=chalk[0];
        for(int i=1;i<n;i++)
            pref[i]=pref[i-1]+chalk[i];
        long long total_req=pref.back();
        k%=total_req;
        
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