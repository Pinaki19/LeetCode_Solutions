typedef long long ll;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ll ans=0;
        int deg[n];
        fill(deg,deg+n,0);
        for(auto& road:roads){
            int u=road[0],v=road[1];
            deg[u]++;deg[v]++;
        }
        int cities[n];
        iota(cities,cities+n,0);
        sort(cities,cities+n,[&deg](int i,int j){
            if(deg[i]==deg[j]) return i<j;
            return deg[i]>deg[j];
        });
        for(int i:cities)
            deg[i]=n--;
        for(auto& road:roads){
            int u=road[0],v=road[1];
            ans+=deg[u]+deg[v];
        }
        return ans;
    }
};