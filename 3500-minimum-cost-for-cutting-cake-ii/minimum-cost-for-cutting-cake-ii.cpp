#define ll long long
class Solution {
public:
    ll minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        priority_queue<int> h(hc.begin(),hc.end());
        priority_queue<int> v(vc.begin(),vc.end());
        ll ans=0;
        ll  hmult=1,vmult=1;
        while(h.size() || v.size()){
            ll hcost=h.size()? h.top():LONG_LONG_MAX;
            ll vcost=v.size()? v.top():LONG_LONG_MAX;
            if(hcost!=LONG_LONG_MAX && hcost>vcost|| vcost==LONG_LONG_MAX){
                ans+=hcost*hmult;
                vmult++;
                h.pop();
            }else{
                ans+=vcost*vmult;
                hmult++;
                v.pop();
            }
        }
        return ans;
    }
};