class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        bool checked=false;

        ios_base::sync_with_stdio(0);

        vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};

        auto is_valid=[&](int i,int j)->bool{
            return i>=0 && i<m && j>=0 && j<n;
        };

        auto fill=[&](int i,int j)->vector<vector<int>>{
            queue<pair<int,int>> q;
            q.push({i,j});
            auto g=grid;
            g[i][j]=2;
            while(q.size()){
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy]:dirs){
                    int nx=x+dx,ny=y+dy;
                    if(is_valid(nx,ny) && g[nx][ny]==1){
                        g[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            return g;
        };

        auto flood=[&](int i,int j)->int{
            vector<vector<int>> g;
            bool found=false;
            for(auto [dx,dy]:dirs){
                int nx=i+dx,ny=j+dy;
                if(is_valid(nx,ny) && grid[nx][ny]==1){
                    found=true;
                    grid[i][j]=0;
                    g=fill(nx,ny);
                    grid[i][j]=1;
                    break;
                }
            }
            if(!found) return 1;
            for(auto [dx,dy]:dirs){
                int nx=i+dx,ny=j+dy;
                if(is_valid(nx,ny) && g[nx][ny]==1){
                    return 1;
                }
            }
            return 2;
        };

        auto check=[m,n](vector<vector<int>>& grid)->bool{
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1) return true;
                }
            }
            return false;
        };

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    if(!checked){
                        checked=true;
                        auto g=fill(i,j);
                        if(check(g)) return 0;
                    }

                    if(flood(i,j)==1) return 1;
                }
            }
        }

        return checked? 2:0;
    }
};