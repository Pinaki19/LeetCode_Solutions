class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dst) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            auto edg=edges[i];
            double prob=succProb[i];
            int u=edg[0],v=edg[1];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

        vector<double> succ(n,0);
        succ[src]=1.0;
        auto comp=[&succ](int i,int j){
            if(succ[i]==succ[j])
                return i<j;
            return succ[i]<succ[j];
        };
        priority_queue<int,vector<int>,decltype(comp)>pq(comp);
        pq.push(src);
        while(pq.size()){
            int v=pq.top();pq.pop();
            for(auto it:adj[v]){
                int t=it.first;
                double prob=it.second;
                double st=succ[t];
                double sv=succ[v];
                if(st<sv*prob){
                    succ[t]=sv*prob;
                    pq.push(t);
                }
            }
        }
        return succ[dst];
    }
};