class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        const int INF=(int) 1e5;
        vector<vector<int>> dist(n,vector<int> (n,INF));
        for(auto e:edges){
            int u=e[0],v=e[1],w=e[2];
            dist[u][v]=dist[v][u]=w;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<(dist[i][j]==INF? -1:dist[i][j])<<"  ";
        //     }
        //     cout<<endl;
        // }
        int ans=0,curMin=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=th)
                    cnt++;
            }
            if( cnt<=curMin){
                curMin=cnt;
                ans=i;
            }
        }

        return ans;
    }
};