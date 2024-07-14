class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        cin.tie(0)->sync_with_stdio(0);
        vector<int> num_child(n,0),ans(n,0);
        vector<vector<int>> adjl(n);
        for(auto edg:edges){
            int u=edg[0],v=edg[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        function<void(int,int)> get_child=[&](int i,int parent)->void{
            for(int j:adjl[i]){
                if(j==parent) continue;
                get_child(j,i);
                num_child[i]+=num_child[j]+1;
            }
        };
        get_child(0,-1);
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<bool> vis(n,false);
        vis[0]=true;
        while(q.size()){
            auto [val,lvl]=q.front();q.pop();
            ans[0]+=lvl;
            for(int i:adjl[val]){
                if(vis[i]) continue;
                q.push({i,lvl+1});
                vis[i]=true;
            }
        }

        //0-->2-->1

        function<void(int,int)> solve=[&](int i,int parent)->void{
            ans[i]=ans[parent]-num_child[i]+(n-2-num_child[i]);
            for(int j:adjl[i]){
                if(j==parent) continue;
                solve(j,i);
            }
        };
       
        for(int i:adjl[0]){
            solve(i,0);
        }
        return ans;
    }
};