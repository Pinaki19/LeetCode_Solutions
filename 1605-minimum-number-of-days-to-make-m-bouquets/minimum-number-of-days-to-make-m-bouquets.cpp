class Solution {
public:
    int minDays(vector<int>& bloom, int m, int k) {
        ios_base::sync_with_stdio(0);
        int n=bloom.size();
        if(n<m*1ll*k) return -1;
        int ans=1e9;
        auto check=[&bloom,&k,&m](int day)->bool{
            int tot=0;
            for(int i=0;i<bloom.size();){
                if(bloom[i]<=day){
                    int t=k;
                    while(t && i<bloom.size() && bloom[i]<=day) i++,t--;
                    if(t==0) tot++;
                }else i++;
            }
            return tot>=m;
        };
        int l=1,r=(int)1e9;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid)){
                ans=min(ans,mid);
                r=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};