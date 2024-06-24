class TreeAncestor {
    int lim,n;
    vector<vector<int>> ancestor;
    vector<int> depth;
public:
    void get_depth(int i,auto& mp){
        for(int x:mp[i]){
            depth[x]=depth[i]+1;
            get_depth(x,mp);
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        ios_base::sync_with_stdio(0);
        map<int,vector<int>> mp;
        this->n=n;
        lim=log2(n)+1;
        ancestor=vector<vector<int>> (n,vector<int> (lim,0));
        depth=vector<int> (n,0);
        parent[0]=0;
        for(int i=1;i<n;i++){
            mp[parent[i]].push_back(i);
            ancestor[i][0]=parent[i];
        }
        for(int j=1;j<lim;j++){
            for(int i=1;i<n;i++)
                ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
        }
        get_depth(0,mp);
        
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node]<k) return -1;
        for(int i=lim-1;i>=0;i--){
            if((k>>i)&1)
                node=ancestor[node][i];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */