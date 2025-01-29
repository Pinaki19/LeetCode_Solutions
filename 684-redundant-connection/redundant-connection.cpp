class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<unordered_set<int>> adj(n,unordered_set<int>());
        for(auto& edg:edges){
            int u=edg[0],v=edg[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int ans=0;
        queue<int> q;
        auto bfs=[&]()->bool{
            int seen=1;
            vector<bool> visited(n,false);
            q.push(1);
            visited[1]=true;
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(int i:adj[x]){
                    if(!visited[i]){
                        visited[i]=true;
                        q.push(i);
                        seen++;
                    }
                }
            }
            return seen==n-1;
        };

        for(int i=0;i<edges.size();i++){
            auto& edg=edges[i];
            int u=edg[0],v=edg[1];
            adj[u].erase(v);
            adj[v].erase(u);
            if(bfs())
                ans=i;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        return edges[ans];
    }
};