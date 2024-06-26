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
    void inorder(TreeNode* root,auto& v){
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* balance(int l,int r,auto& v){
        if(l>r) return nullptr;
        int mid=l+(r-l)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=balance(l,mid-1,v);
        root->right=balance(mid+1,r,v);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        return balance(0,nodes.size()-1,nodes);
    }
};