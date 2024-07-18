/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans=0;
    public List<int[]> solve(TreeNode root,int distance){
        List<int[]> current=new ArrayList<>();
        if(root.left==null && root.right==null){
            current.add(new int[]{1,1});
            return current;
        }
        
        List<int[]> left_ans=new ArrayList<>();
        List<int[]> right_ans=new ArrayList<>();
        if(root.left!=null)
            left_ans=solve(root.left,distance);
        if(root.right!=null)
            right_ans=solve(root.right,distance);
        for(int[] t1:left_ans){
            int dist=t1[0],num=t1[1];
            for(int[] t2:right_ans){
                if(t2[0]+dist<=distance)
                    ans+=num*t2[1];
            }
            if(dist+1<=distance)
                current.add(new int[]{dist+1,t1[1]});
        }
       
        for(int [] t:right_ans){
            if(t[0]+1<=distance){
                current.add(new int[]{t[0]+1,t[1]});
            }
        }
       
        return current;
    }
    public int countPairs(TreeNode root, int distance) {
        ans=0;
        solve(root,distance);
        return ans;
    }
}