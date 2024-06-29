class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0);
        vector<vector<int>> child(n),ans(n);
        vector<set<int>> temp(n);
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
                for(int z:temp[val])
                    temp[x].insert(z);
                temp[x].insert(val);indeg[x]--;
                if(indeg[x]==0) leafs.push_back(x);
            }
        }
        for(int i=0;i<n;i++)
            ans[i]=vector<int> (temp[i].begin(),temp[i].end());
        return ans;
    }
};