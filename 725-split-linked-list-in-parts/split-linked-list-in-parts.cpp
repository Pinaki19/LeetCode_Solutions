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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            n++;
        }
        int mean=n/k;
        int rem=n%k;
        temp=head;

        vector<ListNode*> ans(k,nullptr);
        int i=0;
        while(temp && i<k){
            ListNode* curHead=temp;
            int c= rem>0? 0:1;
            rem--;
            while(temp && c<mean){
                c++;
                temp=temp->next;
            }

            ans[i]=curHead;
            if(temp){
                curHead=temp->next;
                temp->next=nullptr;
                temp=curHead;
            }
            i++;
        }
          
        return ans;
    }
};