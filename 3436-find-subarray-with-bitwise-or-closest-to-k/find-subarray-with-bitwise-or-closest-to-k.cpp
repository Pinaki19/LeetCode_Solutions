class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        vector<array<int,32>> freq(n);
        for(int k=0;k<n;k++){
            int v=nums[k];
            for(int i=0;i<32;i++){
                if(k>0)
                    freq[k][i]=freq[k-1][i];
                if((v>>i)&1){
                    freq[k][i]++;
                }
            }
        }
        int  ans=INT_MAX;

        auto get_ans=[&](int s,int r){
            int l=s;
            int cur=INT_MAX;
            while(l<=r){
                int t=0;
                int mid=l+(r-l)/2;
                if(s==0){
                    for(int i=0;i<32;i++){
                        if(freq[mid][i])
                            t|=(1<<i);
                    }  
                }else{
                    for(int i=0;i<32;i++){
                        if((freq[mid][i]-freq[s-1][i])>0)
                            t|=(1<<i);
                        }   
                }
                 cur=min(cur,abs(t-k));
                if(t<k){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            return cur;
        };

        for(int i=0;i<n;i++){
            int val=get_ans(i,n-1);
            ans=min(ans,val);
        }
        return ans;
    }
};