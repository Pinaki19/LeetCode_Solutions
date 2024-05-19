#define ll long long
class Solution {
public:
   
    long long sumDigitDifferences(vector<int>& nums) {
        
        ll ans=0;
        string s=to_string(nums[0]);
        int n=s.size();
        int freq[11][10];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<n;i++){
            freq[i][s[i]-'0']++;
        }
    
        auto get=[&](int p,int num)->ll{
            string t=to_string(num);
            ll tot=0;
            for(int i=0;i<t.size();i++){
                ll cur=p+1;
                int z=t[i]-'0';
                freq[i][z]+=1;
                tot+=cur-(freq[i][z]);
            }
            
            return tot;
        };
        for(int i=1;i<nums.size();i++){
            ll v=get(i,nums[i]);;
            ans+=v;
        }
        return ans;
    }
};