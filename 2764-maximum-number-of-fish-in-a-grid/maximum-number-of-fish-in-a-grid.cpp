class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        int current=0;
        queue<pair<int,int>> q;
        auto is_valid=[&grid](int x,int y)->bool{
            return x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]>0;
        };
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

        auto bfs=[&](int i,int j)->int{
            q.push({i,j});
            int ans=0;
            current=grid[i][j];
            grid[i][j]=-1;
            while(!q.empty()){
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy]:dir){
                    int nx=x+dx,ny=y+dy;
                    if(is_valid(nx,ny)){
                        current+=grid[nx][ny];
                        grid[nx][ny]=-1;
                        q.push({nx,ny});
                    }
                }
            }
            ans=current;
            current=0;
            return ans;
        };

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]<=0)
                    continue;
                ans=max(ans,bfs(i,j));
            }
        }
        
        return ans;
    }
};