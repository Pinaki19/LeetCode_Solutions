class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0);
        vector<vector<int>> child(n),ans(n);
        int indeg[n];
        deque<int> leafs;
        fill(indeg,indeg+n,0);
        
        for(auto& edg:edges){
            int u=edg[0],v=edg[1];
            child[u].push_back(v);
            indeg[v]++;
        }
        for(int i=0;i<n;i++)
            if(indeg[i]==0) leafs.push_back(i);

        while(leafs.size()){
            int val=leafs.front();
            leafs.pop_front();
            for(int x:child[val]){
                for(int z:ans[val]){
                    auto pos=lower_bound(ans[x].begin(),ans[x].end(),z);
                    if(pos==ans[x].end()) ans[x].push_back(z);
                    else if(*pos!=z) ans[x].insert(pos,z);
                }
                auto pos=lower_bound(ans[x].begin(),ans[x].end(),val);
                if(pos==ans[x].end()) ans[x].push_back(val);
                else if(*pos!=val) ans[x].insert(pos,val);
                indeg[x]--;
                if(indeg[x]==0) leafs.push_back(x);
            }
        }
        return ans;
    }
};