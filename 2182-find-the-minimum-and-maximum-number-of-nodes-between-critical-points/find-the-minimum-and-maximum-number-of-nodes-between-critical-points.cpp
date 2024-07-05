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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int min_dist=INT_MAX,max_dist=0;
        int prev=head->val;
        int next;
        int prev_critical=-1;
        head=head->next;
        int n=1;
        while(head->next){
            next=head->next->val;
            if(head->val>max(prev,next) || head->val<min(prev,next)){
                if(prev_critical>0){
                    min_dist=min(min_dist,n-prev_critical);
                    max_dist+=n-prev_critical;
                }
                prev_critical=n;
            }
            n++;
            prev=head->val;
            head=head->next;
        }
        if(max_dist==0)
            return {-1,-1};
        return {min_dist,max_dist};
    }
};