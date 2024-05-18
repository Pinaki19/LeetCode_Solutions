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
    int distribute(TreeNode root){
        if(root==null) return 0;
        int leftCoins=distribute(root.left);
        int rightCoins=distribute(root.right);
        int total=leftCoins+rightCoins;
        root.val=root.val+total;
        ans+=Math.abs(root.val-1);
        return root.val-1;
    }
    public int distributeCoins(TreeNode root) {
        ans=0;
        distribute(root);
        return ans;
    }
}