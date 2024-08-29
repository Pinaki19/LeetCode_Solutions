class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        ios_base::sync_with_stdio(0);
        int ans=0;
        int n=stones.size();
        const int lim=1e3+1;
        bitset<lim> bs;
        bs.reset();

        unordered_map<int,vector<int>> ri,ci;
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            int rv=stones[i][0],cv=stones[i][1];
            ri[rv].push_back(i);
            ci[cv].push_back(i);
        }

        auto bfs=[&](int x,int y)->int{
            int num=0;
            q.push({x,y});
            while(q.size()){
                auto [rv,cv]=q.front();
                num++;
                q.pop();
                for(int i:ri[rv]){
                    if(!bs[i])
                        bs[i]=1,q.push({stones[i][0],stones[i][1]});
                }
                for(int i:ci[cv]){
                    if(!bs[i])
                        bs[i]=1,q.push({stones[i][0],stones[i][1]});
                }
            }
            return num-1;
        };

        for(int i=0;i<n;i++){
            if(bs[i]==0){
                bs[i]=1;
                ans+= bfs(stones[i][0],stones[i][1]);
            }
        }

        return ans;
    }
};