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
    int gcd(int a,int b){
        while(b){
            int t=a%b;
            a=b;
            b=t;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        int g;
        while(temp->next){
            g=gcd(temp->val,temp->next->val);
            temp->next=new ListNode(g,temp->next);
            temp=temp->next;
            temp=temp->next;
        }
        return head;
    }
};