class Solution {
public:
    const int INF=(int)1e9+7;
    
    int dijkstra(int src,int dest,auto& adj){
        int n=adj.size();
        vector<int> dist(n,INF);
        auto comp=[&](int i,int j){
            if(dist[i]==dist[j])
                return i<j;
            return dist[i]<dist[j];
        };
        priority_queue<int,vector<int>,decltype(comp)> pq(comp);
        dist[src]=0;
        pq.push(src);
        while(pq.size()){
            int t=pq.top();
            pq.pop();
            for(auto [ind,wt]:adj[t]){
                if(dist[ind]>dist[t]+wt){
                    dist[ind]=dist[t]+wt;
                    pq.push(ind);
                }
            }
        }
        return dist[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
       vector<vector<array<int,2>>> adj(n);
       vector<int> negetive;
       
        for(int i=0;i<edges.size();i++){
            auto edge=edges[i];
            int u=edge[0],v=edge[1];
            int wt=edge[2];
            if(wt==-1){
               negetive.emplace_back(i);
            }else{
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
        }
        int dist=dijkstra(src,dest,adj);
        if(dist<target){
            return {};
        }

        if(dist>target){
            for(int i:negetive){
                auto edge=edges[i];
                int u=edge[0],v=edge[1];
                adj[u].push_back({v,1});
                adj[v].push_back({u,1});
                dist=dijkstra(src,dest,adj);
                if(dist<=target){
                    edges[i][2]=target-dist+1;
                    dist=target;
                    break;
                }
                edges[i][2]=1;
            }
        }

        if(dist!=target)
            return {};
        
        for(auto& edge:edges){
            int wt=edge.back();
            if(wt==-1)
                edge[2]=2e9;
        }

        return edges;
    }
};