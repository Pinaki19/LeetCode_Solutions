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
    int last=0;
    TreeNode* solve(string& s,int i,int d){
        if(last>=s.size())
            return nullptr;
        int cur_d=0;
        while(i<s.size() && s[i]=='-'){
            cur_d++;i++;
        }
        if(cur_d<=d)
            return nullptr;
        int val=0;
        while(i<s.size() && isdigit(s[i])){
            int k=s[i]-'0';
            val=val*10+k;
            i++;
        }
        last=i;
        TreeNode* node=new TreeNode(val);
        node->left=solve(s,last,d+1);
        node->right=solve(s,last,d+1);
        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        return solve(traversal,0,-1);
    }
};