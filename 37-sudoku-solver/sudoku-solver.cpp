class Solution {
public:
    int blockNum(int i,int j){
       return ((i/3)*3)+j/3;
    }
    template<int size>
    void solve(int i,int j,short row[size],short col[size],short block[size],auto& board,bool& s){
        int nextR= j+1==9? i+1:i;
        int nextC= j+1==9? 0:j+1;
        if(i==9){
            s=true;
            return;
        }
        if(board[i][j]!='.') return solve<size>(nextR,nextC,row,col,block,board,s);
        for(int val=1;val<10;val++){
            if((row[i]&(1<<val))==0 && (col[j]&(1<<val))==0 && (block[blockNum(i,j)]&(1<<val))==0){
                row[i]|=(1<<val);
                col[j]|=(1<<val);
                block[blockNum(i,j)]|=(1<<val);
                board[i][j]='0'+val;
                solve<size>(nextR,nextC,row,col,block,board,s);
                if(!s){
                    row[i]^=(1<<val);
                    col[j]^=(1<<val);
                    block[blockNum(i,j)]^=(1<<val);
                    board[i][j]='.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool solved=false;
        short row[10]={0},col[10]={0},block[10]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                char c=board[i][j];
                int val=c-'0';
                row[i]|=(1<<val);
                col[j]|=(1<<val);
                block[blockNum(i,j)]|=(1<<val);
            }
        }
        solve<10>(0,0,row,col,block,board,solved);
    }
};