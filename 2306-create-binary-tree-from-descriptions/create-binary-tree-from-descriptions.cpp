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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        const int lim=100001;
        TreeNode* nodes[lim];
        TreeNode* parents[lim];
        fill(nodes,nodes+lim,nullptr);
        fill(parents,parents+lim,nullptr);
        for(auto desc:descriptions){
            int p=desc[0],c=desc[1],is_left=desc[2];
            nodes[c]=nodes[c]? nodes[c]:new TreeNode(c);
            nodes[p]= nodes[p]? nodes[p]:new TreeNode(p);
            parents[c]=nodes[p];
            if(is_left) nodes[p]->left=nodes[c];
            else nodes[p]->right=nodes[c];
        }

        for(int i=0;i<lim;i++){
            if(nodes[i] && parents[i]==nullptr)
                return nodes[i];
        }
        return nullptr;
    }
};