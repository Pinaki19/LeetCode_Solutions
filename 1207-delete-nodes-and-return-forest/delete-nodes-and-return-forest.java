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
    public boolean solve(List<TreeNode> ans,TreeNode root,Set<Integer> del,int parent){
        if(root==null) return false;
        boolean exist_val=false;
        boolean exist_parent=false;
        if(del.contains(root.val))
            exist_val=true;
        if(del.contains(parent))
            exist_parent=true;
        boolean res_left=solve(ans,root.left,del,root.val);
        boolean res_right=solve(ans,root.right,del,root.val);
        if(res_left) root.left=null;
        if(res_right) root.right=null;
        if(!exist_val & exist_parent)
            ans.add(root);
        return exist_val;
    }
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        List<TreeNode> ans=new ArrayList<>();
        Set<Integer> del=new HashSet<Integer>();
        for(int i:to_delete)
            del.add(i);
        solve(ans,root,del,to_delete[0]);
    
        return ans;
    }
}