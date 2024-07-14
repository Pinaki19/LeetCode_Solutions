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
    int distributeCoins(TreeNode* root) {
        function<int(TreeNode*,int&)> solve=[&](TreeNode* root,int& ans)->int{
            if(root==nullptr) return 0;
            int left=solve(root->left,ans);
            int right=solve(root->right,ans);
            int req_or_need=root->val+left+right-1;
            ans+=abs(req_or_need);
            return req_or_need;
        };
        int ans=0;
        solve(root,ans);
        return ans;
    }
};