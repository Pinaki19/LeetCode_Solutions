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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        ios_base::sync_with_stdio(0);
        unordered_map<TreeNode*,int> depths;
        TreeNode *u=nullptr,*v=nullptr;
        function<TreeNode*(TreeNode*)> get_LCA=[&](TreeNode* root)->TreeNode*{
             if (root == NULL||root->val == startValue || root->val == destValue)
                return root;
            TreeNode* l = get_LCA(root->left);
            TreeNode* r = get_LCA(root->right);
            if (l == NULL) return r;
            if (r == NULL) return l;
            return root;
        };
        auto LCA=get_LCA(root);

        function<void(TreeNode*,int)> get_depths=[&](TreeNode* root,int dep)->void{
            if(!root) return;
            if(root->val==startValue)
                u=root;
            if(root->val==destValue)
                v=root;
            depths[root]=dep;
            get_depths(root->left,dep+1);
            get_depths(root->right,dep+1);
        };
        get_depths(root,0);

        string ans="";
        int diff=depths[u]-depths[LCA];
        for(int i=0;i<diff;i++)
            ans+='U';
        if(LCA==v) return ans;
        string left="";
        function<bool(TreeNode*)> solve=[&](TreeNode* node)->bool{
            if(!node) return false;
            if(node->val==destValue)
                return true;
            bool to_left=solve(node->left);
            if(to_left){
                left+='L';
                return true;
            }
            bool to_right=solve(node->right);
            if(to_right){
                left+='R';
                return true;
            }
            return false;
        };
        solve(LCA);
        reverse(left.begin(),left.end());
        return ans+left;
    }
};