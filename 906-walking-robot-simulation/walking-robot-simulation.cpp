class Solution {
public:
    pair<int,int> getDirVector(char c){
        switch(c){
            case 'E':
                return {1,0};
            case 'W':
                return {-1,0};
            case 'N':
                return {0,1};
            case 'S':
                return {0,-1};
        }
        return {0,0};
    }
    char getDir(char c,int command){
        if(c=='E'){
            if(command==-1)
                return 'S';
            else
                return 'N';
        }else if(c=='W'){
            if(command==-1)
                return 'N';
            else
                return 'S';
        }else if(c=='N'){
            if(command==-1)
                return 'E';
            else
                return 'W';
        }else{
            if(command==-1)
                return 'W';
            else
                return 'E';
        }
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        char curdir='N';
        auto it=getDirVector(curdir);
        int dx=it.first,dy=it.second;
        int ans=0;
        int x=0,y=0;
        set<vector<int>> s(obs.begin(),obs.end());

        for(int i:commands){
            if(i<0){
                curdir=getDir(curdir,i);
                auto it=getDirVector(curdir);
                dx=it.first;dy=it.second;
            }else{
                if(dx==0){
                    for(int k=1;k<=i;k++){
                        if(s.find({x,y+dy})!=s.end())
                            break;
                        y+=dy;
                    }
                }else{
                    for(int k=1;k<=i;k++){
                        if(s.find({x+dx,y})!=s.end())
                            break;
                        x+=dx;
                    }
                }
                ans=max(ans,x*x+y*y);
            }
        }
        return ans;
    }
};