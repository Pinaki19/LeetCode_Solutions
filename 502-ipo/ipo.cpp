class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios_base::sync_with_stdio(0);
        priority_queue<int> pq;
        vector<pair<int,int>> vp;
        for(int i=0;i<profits.size();i++)
            vp.push_back({capital[i],profits[i]});
        sort(vp.begin(),vp.end());
        int i=0;
        while(i<vp.size() && vp[i].first<=w)
            pq.push(vp[i++].second);
        while(k--){
            if(pq.empty()) break;
            w+=pq.top();pq.pop();
            while(i<vp.size() && vp[i].first<=w)
                pq.push(vp[i++].second);
        }
        return w;
    }
};