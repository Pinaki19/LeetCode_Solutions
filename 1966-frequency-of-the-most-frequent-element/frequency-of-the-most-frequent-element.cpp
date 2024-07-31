class Solution {
public:
    using ll=long long;
    int maxFrequency(vector<int>& nums, int k) {
        const int lim=(int)1e5+1;
        int freq[lim]={0};
        ll ans=0;

        for(int i:nums)
            freq[i]++;
        ll tot=0,prev=0;
        ll l=0,r=0;
        ll cost=0;
        while(r<lim){
            cost+=(r-prev)*tot;
            tot+=freq[r];
            while(cost>k){
                ll subtr=(r-l)*freq[l];
                if(cost-subtr>=k){
                    tot-=freq[l++];
                    cost-=subtr;
                } 
                else{
                    ll d=cost-k;
                    int oc=(r-l);
                    int m=ceil((float)d/oc);
                    cost-=m*oc;
                    tot-=m;
                    freq[l]-=m;
                }
                
            }

            prev=r;
            ans=max(ans,tot);
            r++;
        }
        return ans;
    }
};