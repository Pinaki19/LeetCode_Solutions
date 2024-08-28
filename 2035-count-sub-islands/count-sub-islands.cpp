class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<pair<int,int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        auto is_valid=[&](int i,int j)->bool{
            return i>=0 && i<grid1.size() && j>=0 && j<grid1[0].size();
        };

        auto flood_fill=[&](int x,int y)->bool{
            queue<pair<int,int>> q;
            bool valid_island=grid1[x][y]==1? true:false;

            q.push({x,y});
            grid2[x][y]=-1;
            while(q.size()){
                auto [i,j]=q.front();
                q.pop();
                for(auto [dx,dy]:dir){
                    int nx=i+dx,ny=j+dy;
                    if(is_valid(nx,ny) && grid2[nx][ny]==1){
                        if(grid1[nx][ny]!=1)
                            valid_island=false;
                        grid2[nx][ny]=-1;
                        q.push({nx,ny});
                    }
                }
            }

            return valid_island;
        };

        int ans=0;

        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[i].size();j++){
                if(grid2[i][j]==1){
                    ans+=flood_fill(i,j);
                }
            }
        }
        return ans;
    }
};