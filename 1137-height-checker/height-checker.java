class Solution {
    public int heightChecker(int[] heights) {
        int n=heights.length;
        int[] expected=new int[n];
        System.arraycopy(heights,0,expected,0,n);
        Arrays.sort(expected);
        int ans=0;
        for(int i=0;i<n;i++){
            if(heights[i]!=expected[i]) ans++;
        }
        return ans;
    }
}