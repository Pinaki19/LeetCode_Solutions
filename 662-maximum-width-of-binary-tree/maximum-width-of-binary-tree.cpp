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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int ans=0;
        while(q.size()){
            int l=q.size();
            int f_ind=0,l_ind=0;
            for(int i=0;i<l;i++){
                auto [node,ind]=q.front();
                q.pop();
                if(i==0)
                    f_ind=ind;
                if(i==l-1)
                    l_ind=ind;
                if(node->left)
                    q.push({node->left,static_cast<unsigned long long>(2)*ind+1});
                if(node->right)
                    q.push({node->right,static_cast<unsigned long long>(2)*ind+2});
            }
            ans=max(ans,l_ind-f_ind+1);
        }

        return ans;
    }
};