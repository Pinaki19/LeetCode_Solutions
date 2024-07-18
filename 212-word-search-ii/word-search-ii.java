class Trie{
    Trie[] child=new Trie[26];
    boolean isEnd=false;
    boolean matched=false;
    Trie(){
        Arrays.fill(child,null);
    }
};
class Solution {
    int[][] dir={{1,0},{-1,0},{0,1},{0,-1}};
    boolean[][] visited;
    boolean isValid(int x,int y,char[][] board){
        return x>=0 && x<board.length && y>=0 && y<board[0].length && !visited[x][y];
    }

    List<int[]> getAllLocations(char c,boolean start,int x,int y,char[][] board){
        List<int[]> locations=new ArrayList<int[]>();
        if(start){
            for(int i=0;i<board.length;i++){
                for(int j=0;j<board[0].length;j++){
                    if(board[i][j]==c)
                        locations.add(new int[] {i,j});
                }
            }
        }else{
            for(int[] d:dir){
                int nx=x+d[0],ny=y+d[1];
                if(isValid(nx,ny,board) && board[nx][ny]==c)
                    locations.add(new int[] {nx,ny});
            }
        }
        return locations;
    }

    void traverse(Trie root,boolean start,int prevx,int prevy,char c,String cur,Set<String> ans,char[][] board){
        if(root==null) return;
        List<int[]> locations=getAllLocations(c,start,prevx,prevy,board);
        if(locations.size()==0) return;
        cur+=c;
        if(root.isEnd){
            if(ans.contains(cur)==false)
                 ans.add(cur);
            
        }
           
        for(int[] loc:locations){
            visited[loc[0]][loc[1]]=true;
            for(int i=0;i<26;i++){
                if(root.child[i]!=null){
                    char t=(char)('a'+i);
                    traverse(root.child[i],false,loc[0],loc[1],t,cur,ans,board);
                }
            }
            visited[loc[0]][loc[1]]=false;
        }
    }
    public List<String> findWords(char[][] board, String[] words) {
        int m=board.length,n=board[0].length;
        visited=new boolean[m][n];
        Trie root=new Trie();
        for(String word:words){
            Trie temp=root;
            for(int i=0;i<word.length();i++){
                int z=(int)(word.charAt(i)-'a');
                if(temp.child[z]==null)
                    temp.child[z]=new Trie();
                temp=temp.child[z];
            }
            temp.isEnd=true;
        }
        for(boolean[] t:visited)
            Arrays.fill(t,false);
        Set<String> ans=new HashSet<>();
        for(int i=0;i<26;i++){
            if(root.child[i]!=null){
                char t=(char)('a'+i);
                traverse(root.child[i],true,0,0,t,"",ans,board);
            }
        }
        return new ArrayList<String> (ans);
    }
}