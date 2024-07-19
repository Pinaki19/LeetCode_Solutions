class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> ans=new ArrayList<>();
        int m=matrix.length;
        int n=matrix[0].length;
        int[] colMax=new int[n];
        int[] rowMin=new int[m];
        Arrays.fill(rowMin,Integer.MAX_VALUE);
        Arrays.fill(colMax,Integer.MIN_VALUE);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rowMin[i]=Math.min(rowMin[i],matrix[i][j]);
                colMax[j]=Math.max(colMax[j],matrix[i][j]);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(colMax[j]==rowMin[i]){
                    ans.add(colMax[j]);
                    break;
                }
        }
        return ans;
    }
}