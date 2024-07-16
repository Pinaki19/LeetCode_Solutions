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
        string to_src="",to_dst="";
        function<void(TreeNode*)> solve=[&,&x=startValue,&y=destValue](TreeNode* root)->void{
            if(!root) return;
            solve(root->left);
            solve(root->right);
            if(root->left && root->left->val==x || root->right && root->right->val==x){
                to_src+='U';
                x=root->val;
            }
            if(root->left && root->left->val==y){
                to_dst+='L';
                y=root->val;
            }
            else if(root->right && root->right->val==y){
                to_dst+='R';
                y=root->val;
            }
            if(x==y){
                x=-1;
                y=-1;
                return;
            }
                
        };
        solve(root);
        reverse(to_dst.begin(),to_dst.end());
        return to_src+to_dst;
    }
};