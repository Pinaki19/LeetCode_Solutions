class Solution {
    static class Mycomp implements Comparator<Integer>{
        int[] heights;
        Mycomp(int[] heights){
            this.heights=heights;
        }
        public int compare(Integer i1,Integer i2){
            return (int)Math.signum((double)(heights[i2]-heights[i1]));
        }
    };
    public String[] sortPeople(String[] names, int[] heights) {
        int n=names.length;
        String[] ans=new String[n];
        Integer[] indices=new Integer[n];
        for(int i=0;i<n;i++)
            indices[i]=i;
        
        Arrays.sort(indices,new Mycomp(heights));
        for(int i=0;i<n;i++)
            ans[i]=names[indices[i]];
        
        return ans;
    }
}