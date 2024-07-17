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
    public TreeNode solve(List<TreeNode> ans,TreeNode root,Set<Integer> del){
        if(root==null) return null;
        root.left=solve(ans,root.left,del);
        root.right=solve(ans,root.right,del);
        boolean contains=del.contains(root.val);
        if(root.left!=null && contains){
            ans.add(root.left);
            root.left=null;
        }
        if(root.right!=null && contains){
            ans.add(root.right);
            root.right=null;
        }
        return contains? null:root;
    }
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        List<TreeNode> ans=new ArrayList<>();
        Set<Integer> del=new HashSet<Integer>();
        for(int i:to_delete)
            del.add(i);
        root=solve(ans,root,del);
        if(root!=null)
            ans.add(root);
        return ans;
    }
}