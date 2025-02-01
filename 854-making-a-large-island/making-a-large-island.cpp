#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,abm,bmi2")

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>> (n));
        vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                parent[i][j]=make_pair(i,j);
        }

        auto find_parent=[&](auto self,int i,int j)->pair<int,int>{
            auto [x,y]=parent[i][j];
            if(x==i && y==j)
                return make_pair(x,y);
            parent[i][j]=self(self,x,y);
            return parent[i][j];
        };

        auto is_valid=[&](int i,int j)->bool{
            return i>=0 && i<n && j>=0 && j<n;
        };

        auto bfs=[&](int i,int j)->int{
            q.push({i,j});
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                auto [px,py]=find_parent(find_parent,x,y);
                for(auto [dx,dy]:directions){
                    int nx=x+dx,ny=y+dy;
                    if(is_valid(nx,ny) && grid[nx][ny]==1){
                        grid[px][py]+=1;
                        grid[nx][ny]=2;
                        parent[nx][ny]={px,py};
                        q.push({nx,ny});
                    }
                }
            }
            return grid[i][j];
        };

        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    auto [x,y]=find_parent(find_parent,i,j);
                    if(x==i && y==j)
                        ans=max(ans,bfs(i,j));
                }
            }
        }

        auto get_size=[&](int i,int j)->int{
            auto [x,y]=find_parent(find_parent,i,j);
            return grid[x][y];
        };
        set<pair<int,int>> s;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int total=0;
                    for(auto [dx,dy]:directions){
                        int nx=i+dx,ny=j+dy;
                        if(is_valid(nx,ny))
                            s.insert(find_parent(find_parent,nx,ny));
                    }
                    for(auto [x,y]:s)
                        total+=get_size(x,y);
                    ans=max(ans,1+total);
                    s.clear();
                }
            }
        }

        return ans;
    }
};