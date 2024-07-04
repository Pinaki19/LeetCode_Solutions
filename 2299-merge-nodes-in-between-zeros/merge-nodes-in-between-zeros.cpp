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
    ListNode* mergeNodes(ListNode* head) {
        ios_base::sync_with_stdio(0);
        if(!head) return nullptr;
        if(head->val!=0||head->val==0 && !head->next){
           return head->next=mergeNodes(head->next);
        }else{
            ListNode* temp=head->next;
            while(temp && temp->val!=0){
                head->val+=temp->val;
                temp=temp->next;
            }
            if(temp && temp->val==0)
                head->next=mergeNodes(temp);
            return head;
        }
        return head;
    }
};