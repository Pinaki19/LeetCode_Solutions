class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        priority_queue<int> h(hc.begin(),hc.end());
        priority_queue<int> v(vc.begin(),vc.end());
        int ans=0;
        int hmult=1,vmult=1;
        while(h.size() || v.size()){
            int hcost=h.size()? h.top():INT_MAX;
            int vcost=v.size()? v.top():INT_MAX;
            if(hcost!=INT_MAX && hcost>vcost|| vcost==INT_MAX){
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