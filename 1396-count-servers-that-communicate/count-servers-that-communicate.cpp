class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            int first=-1;
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]){
                    if(first<0)
                        first=j;
                    else{
                        grid[i][first]++;
                        grid[i][j]++;
                    }
                }
            }
        }
        for(int j=0;j<grid[0].size();j++){
            int first=-1;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]){
                    if(first<0)
                        first=i;
                    else{
                        grid[first][j]++;
                        grid[i][j]++;
                    }
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]>1)
                    count++;
            }
        }
        return count;
    }
};