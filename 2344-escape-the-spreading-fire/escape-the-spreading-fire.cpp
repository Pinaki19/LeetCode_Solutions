class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        queue<pair<int,int>> q;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dist_fire(m,vector<int> (n,(int)1e9+100000));
        vector<vector<int>> dist_player(m,vector<int> (n,(int) 1e9));
        auto is_valid=[&m,&n ,&grid](int i,int j)->bool{
            return i>=0 && i<m && j>=0 && j<n && !grid[i][j];
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist_fire[i][j]=0;
                }
            }
        }
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(q.size()){
            auto [x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(is_valid(nx,ny) && dist_fire[nx][ny]>dist_fire[x][y]+1){
                    dist_fire[nx][ny]=dist_fire[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        q.push({0,0});
        dist_player[0][0]=0;
        while(q.size()){
            auto [x,y]=q.front();
            q.pop();
            for(auto [dx,dy]:dir){
                int nx=x+dx,ny=y+dy;
                if(is_valid(nx,ny) && dist_player[nx][ny]>dist_player[x][y]+1){
                    dist_player[nx][ny]=dist_player[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        if(dist_fire[m-1][n-1]<dist_player[m-1][n-1]) return -1;

        auto check=[&](int day)->bool{
            q=queue<pair<int,int>> ();
            q.push({0,0});
            vector<vector<bool>> vis(m,vector<bool> (n,false));
            vis[0][0]=true;
            while(q.size()){
                auto [x,y]=q.front();
                q.pop();
                if(x==m-1 && y==n-1 && dist_fire[x][y]>=dist_player[x][y]+day) return true;
                if(dist_fire[x][y]<=dist_player[x][y]+day) continue;
                
                for(auto [dx,dy]:dir){
                    int nx=x+dx,ny=y+dy;
                    if(is_valid(nx,ny) && !vis[nx][ny] && !grid[nx][ny]){
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                    }
                }
            }
            return false;
        };
        int ans=-1;
        int l=0,r=(int)1e9;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid)){
                ans=max(ans,mid);
                l=mid+1;
            }else
                r=mid-1;
        }
        return ans;;
    }
};