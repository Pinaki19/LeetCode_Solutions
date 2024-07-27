class Solution {
public:
    using ll=long long;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ios_base::sync_with_stdio(0);
        const int INF=(int)1e7;
        vector<vector<int>> costs(26,vector<int> (26,INF));
        for(int i=0;i<cost.size();i++){
            int t1=original[i]-'a';
            int t2=changed[i]-'a';
            costs[t1][t2]=min(costs[t1][t2],cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(i==j) continue;
                    if(costs[i][j]>costs[i][k]+costs[k][j])
                        costs[i][j]=costs[i][k]+costs[k][j];
                }
            }
        }
        ll ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]==target[i]) continue;
            int c1=source[i]-'a';
            int c2=target[i]-'a';
            if(costs[c1][c2]==INF) return -1;
            ans+=costs[c1][c2];
        }   
        return ans;
    }
};