/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int from_root){
        if(!root) return from_root;
        root->val+=solve(root->right,from_root);
        int val=solve(root->left,root->val);
        return val;
    }
    TreeNode* bstToGst(TreeNode* root) {
       solve(root,0);
       return root;
    }
};