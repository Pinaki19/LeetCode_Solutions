class Solution {
public:
    int get_parent(int * parent,int a){
        if(parent[a]==a) return a;
        return get_parent(parent,parent[a]);
    }
    bool Union(int * parent,int a,int b,int *sz){
        int p_a=get_parent(parent,a);
        int p_b=get_parent(parent,b);
        if(p_a==p_b) return false;
        if(sz[p_a]>sz[p_b]){
            sz[p_a]+=sz[p_b];
            parent[p_b]=p_a;
        }else{
            sz[p_b]+=sz[p_a];
            parent[p_a]=p_b;
        }
        return true;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[](auto& v1,auto& v2){
            if (v1[0]==v2[0]) return v1[1]<v2[1];
            return v1[0]>v2[0];
        });

        int parent_al[n],parent_bo[n];
        int sz_al[n],sz_bo[n];
        fill(sz_al,sz_al+n,1);
        fill(sz_bo,sz_bo+n,1);
        iota(parent_al,parent_al+n,0);
        iota(parent_bo,parent_bo+n,0);
        int ans=0;
        for(auto edg:edges){
            int type=edg[0],u=edg[1]-1,v=edg[2]-1;
            if(type==3){
                bool res1=Union(parent_al,u,v,sz_al);
                bool res2=Union(parent_bo,u,v,sz_bo);
                if(!res1 && !res2)
                    ans++;
            }else if(type==2){
                if(!Union(parent_bo,u,v,sz_bo))
                    ans++;
            }else{
                if(!Union(parent_al,u,v,sz_al))
                    ans++;
            }
        }
        int mx_al=*max_element(sz_al,sz_al+n),mx_bo=*max_element(sz_bo,sz_bo+n);
        //cout<<mx_al<<"  "<<mx_bo;
        return (mx_al==n && mx_bo==n)? ans:-1;
    }
};