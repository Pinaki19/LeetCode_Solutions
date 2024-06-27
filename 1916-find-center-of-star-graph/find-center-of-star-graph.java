class Solution {
    public int findCenter(int[][] edges) {
        int n=edges.length+1;
        int[] indeg=new int[n+1];
        Arrays.fill(indeg,0);
        int u,v;
        for(int[] edg:edges){
            u=edg[0];v=edg[1];
            indeg[u]++;
            indeg[v]++;
            if(indeg[u]==n-1) return u;
            if(indeg[v]==n-1) return v;
        }
        return -1;
    }
}