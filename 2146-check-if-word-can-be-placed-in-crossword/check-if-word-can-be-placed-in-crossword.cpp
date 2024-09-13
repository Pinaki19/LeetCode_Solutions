class Solution {
public:
    bool isPossible(int ind,string& word,bool isRow,auto& board){
        vector<int> starts;
        if(isRow){
            for(int j=0;j<=board[0].size()-word.size();j++){
                if(board[ind][j]!='#'){
                    if(board[ind][j]==' '||board[ind][j]==word[0])
                        starts.push_back(j);
                }
            }
            bool matched=false;
            for(int i:starts){
                if(i>0 && board[ind][i-1]!='#') continue;
                int last=i+word.size();
                if(last<board[ind].size() && board[ind][last]!='#') continue;
                int l=i,r=last-1;
                int wl=0,wr=word.size()-1;
                while(wl<=wr){
                    char first=board[ind][l];
                    char last=board[ind][r];
                    if((first==' ' || first==word[wl]) && (last==' ' || last==word[wr])){

                    }else{
                        break;
                    }
                    wl++;wr--;
                    l++;r--;
                }
                matched=wl>wr;
                if(matched) break;
            }
            return matched;
        }else{
            for(int i=0;i<=board.size()-word.size();i++){
                if(board[i][ind]!='#'){
                    if(board[i][ind]==' '||board[i][ind]==word[0])
                        starts.push_back(i);
                }
            }
            bool matched=false;
            for(int i:starts){
                if(i>0 && board[i-1][ind]!='#') continue;
                int last=i+word.size();
                if(last<board.size() && board[last][ind]!='#') continue;
                int l=i,r=last-1;
                int wl=0,wr=word.size()-1;
                while(wl<=wr){
                    char first=board[l][ind];
                    char last=board[r][ind];
                    if((first==' ' || first==word[wl]) && (last==' ' || last==word[wr])){

                    }else{
                        break;
                    }
                    wl++;wr--;
                    l++;r--;
                }
                matched=wl>wr;
                if(matched) break;
            }
            return matched;
        }
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        vector<int> rows,columns;
        for(int i=0;i<m;i++){
            int cnt=0;
            bool found=false;
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    if(found) break;
                    else continue;
                }
                cnt++;
            }
            if(cnt>=word.size())
                rows.push_back(i);
        }

        for(int j=0;j<n;j++){
            int cnt=0;
            bool found=false;
            for(int i=0;i<m;i++){
                if(board[i][j]=='#'){
                    if(found) break;
                    else continue;
                }
                cnt++;
            }
            if(cnt>=word.size())
                columns.push_back(j);
        }
        string rev=word;
        reverse(rev.begin(),rev.end());
        for(int i:rows){
            if(isPossible(i,word,true,board)) return true;
            if(isPossible(i,rev,true,board)) return true;
        }

        for(int i:columns){
            if(isPossible(i,word,false,board)) return true;
            if(isPossible(i,rev,false,board)) return true;
        }
        return false;
    }
};