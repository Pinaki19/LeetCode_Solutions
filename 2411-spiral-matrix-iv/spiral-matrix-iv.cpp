/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void fill(int lb,int rb,int ub,int db,auto& ans,ListNode* head){
        if(!head||lb>rb||ub>db) return;
        for(int j=lb;j<=rb && head;j++){
            ans[ub][j]=head->val;
            head=head->next;
        }
        for(int i=ub+1;i<=db && head;i++){
            ans[i][rb]=head->val;
            head=head->next;
        }
        if(ub!=db){
            for(int j=rb-1;j>=lb && head;j--){
                ans[db][j]=head->val;
                head=head->next;
            }
        }
        if(lb!=rb){
            for(int i=db-1;i>ub && head;i--){
                ans[i][lb]=head->val;
                head=head->next;
            }
        }
        fill(lb+1,rb-1,ub+1,db-1,ans,head);
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        fill(0,n-1,0,m-1,ans,head);
        return ans;
    }
};