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
    int last,n;
    TreeNode solve(String t,int d){
        if(last>=n) return null;
        int val=0;
        int i=last,depth=0;
        while(i<n && t.charAt(i)=='-'){
            depth++;i++;
        } 
        if(depth<=d) return null;

        while(i<n && Character.isDigit(t.charAt(i))){
            int v=(int)t.charAt(i)-48;
            val*=10;
            val+=v;
            i++;
        }
        TreeNode node=new TreeNode(val);
        last=i;
        node.left=solve(t,d+1);
        node.right=solve(t,d+1);
        return node;
    }
    public TreeNode recoverFromPreorder(String t) {
        this.n=t.length();
        last=0;
        return solve(t,-1);
    }
}