class TreeAncestor {
    int lim;
    vector<vector<int>> ancestor;
public:
    TreeAncestor(int n, vector<int>& parent) {
        ios_base::sync_with_stdio(0);
        lim=log2(n)+1;
        ancestor=vector<vector<int>> (n,vector<int> (lim,-1));
        for(int i=0;i<n;i++)
            ancestor[i][0]=parent[i];

        for(int j=1;j<lim;j++){
            for(int i=0;i<n;i++){
                if(ancestor[i][j-1]!=-1)
                    ancestor[i][j]=ancestor[ancestor[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=lim-1;i>=0;i--){
            if((k>>i)&1)
                node=ancestor[node][i];
            if(node==-1) return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */