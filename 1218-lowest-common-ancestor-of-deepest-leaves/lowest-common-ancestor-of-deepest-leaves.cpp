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
    int depths[1001]={0};
    const static int depth_lim=10;
    TreeNode* ancestors[1001][depth_lim];
public:
   
    void traverse(TreeNode* root,TreeNode* parent,int dep,TreeNode** v1,TreeNode** v2,int& d1,int& d2){
        if(!root) return;
        int v=root->val;
        ancestors[v][0]=parent;
        depths[v]=dep;
        traverse(root->left,root,dep+1,v1,v2,d1,d2);
        traverse(root->right,root,dep+1,v1,v2,d1,d2);
        if(dep>=min(d1,d2)){
            if(dep>d1){
                d1=dep;
                *v1=root;
            }else{
                d2=dep;
                *v2=root;
            }
        }
    }
    TreeNode* findLca(TreeNode* node1,TreeNode* node2){
        if(node1==node2||depths[node1->val]>depths[node2->val]) return node1;
        for(int j=1;j<depth_lim;j++){
            for(int i=1;i<1001;i++){
                if(ancestors[i][j-1])
                    ancestors[i][j]=ancestors[ (ancestors[i][j-1])->val][j-1];
            }
        }

        if(depths[node1->val]<depths[node2->val]) swap(node1,node2);
        int diff=depths[node1->val]-depths[node2->val];
        for(int i=31;i>=0;i--){
            if((diff>>i)&1)
                node1=ancestors[node1->val][i];
        }
        if(node1==node2) return node1;
        for(int i=depth_lim-1;i>=0;i--){
            if(ancestors[node1->val][i]!=ancestors[node2->val][i]){
                node1=ancestors[node1->val][i];
                node2=ancestors[node2->val][i];
            }
        }
        return ancestors[node1->val][0];
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        TreeNode* v1=root,*v2=root;
        int d1=0,d2=0;
        traverse(root,nullptr,0,&v1,&v2,d1,d2);
        return findLca(v1,v2);
    }
};