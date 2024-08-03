class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int cur=0;
        int l=0,r=0;
        int cnt=0;
        while(l<n){
            if(cnt==n) return l;
            int t=gas[r]-cost[r];
            cur+=t;
            cnt++;
            while(l<n && cur<0){
                cur-=(gas[l]-cost[l]);
                l++;
                cnt--;
            }
            r++;
            r%=n;
        }

        return -1;
    }
};