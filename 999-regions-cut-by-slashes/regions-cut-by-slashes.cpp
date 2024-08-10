class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int ans=0;
        int n=grid.size();
        vector<vector<array<int,3>>> board(n,vector<array<int,3>>(n,array<int,3> {0,0,0}));
        
        auto translate_dir=[](char c)->pair<int,int>{
            if(c=='u')
                return {-1,0};
            if(c=='d')
                return {1,0};
            if(c=='l')
                return {0,-1};
            return {0,1};
        };

        auto portion_to_dir=[](int type,int p)->vector<char>{
            if(type==0)
                return {'u','d','l','r'};
            if(type==1){
                if(p==1)
                    return {'u','l'};
                return {'d','r'};
            }else{
                if(p==2)
                    return {'u','r'};
                return {'d','l'};
            }
        };

        int row=0,col=0;
        for(int i=0;i<n;i++,row++){
            col=0;
            for(int j=0;j<grid[i].size();j++,col++){
                if(grid[i][j]=='/'){
                    board[row][col][0]=1;
                }  
                else if(grid[i][j]=='\\'){
                    board[row][col][0]=2;
                }
            }
        }

        auto is_valid=[n](int i,int j)->bool{
            return i>=0 && i<n && j>=0 && j<n;
        };

        auto char_to_portion=[](char c,int type)->int{
           if(type<=1){
                if(c=='u'||c=='l')
                    return 2;
                return 1;
           }
           if(c=='u'||c=='r')
                return 1;
            return 2;
        };

        function<void(int,int,int,int)> flood_fill=[&](int i,int j,int portion,int r){
            if(i>=n || j>=n || board[i][j][portion]!=0) return;
            int type=board[i][j][0];
            if(type==0)
                board[i][j][1]=board[i][j][2]=r;

            auto dirs=portion_to_dir(type,portion);
            board[i][j][portion]=r;
            for(char c:dirs){
                auto [dx,dy]=translate_dir(c);
                int nx=i+dx,ny=j+dy;
                if(is_valid(nx,ny)){
                    flood_fill(nx,ny,char_to_portion(c,board[nx][ny][0]),r);
                }
            }
        };

        int reg=100;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j][1]==0){
                    ans++;
                    flood_fill(i,j,1,reg++); 
                }
                if(board[i][j][2]==0){
                    ans++;
                    flood_fill(i,j,2,reg++); 
                }
            }
        }

        for(auto& v:board){
            for(auto t:v){
                cout<<t[0]<<":"<<t[1]<<":"<<t[2]<<" ";
            }
            cout<<endl;
        }

        return ans;
    }
};