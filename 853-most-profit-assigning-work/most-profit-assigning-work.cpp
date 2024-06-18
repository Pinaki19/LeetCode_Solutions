class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(),worker.end());
        vector<pair<int,int>> vp;
        for(int i=0;i<profit.size();i++)
            vp.push_back({difficulty[i],profit[i]});

        sort(vp.begin(),vp.end());
        priority_queue<int> pq;
        int i=0;
        int ans=0;

        for(int val:worker){
            while(i<vp.size() && vp[i].first<=val)
                pq.push(vp[i++].second);
            if(pq.size())
                ans+=pq.top();
        }

        return ans;
    }
};