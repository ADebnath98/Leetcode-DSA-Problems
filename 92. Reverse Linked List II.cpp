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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode*curr=head;
        ListNode* leftpre=dummy;
        for(int i=0;i<left-1;i++)
        {
            leftpre=curr;
            curr=curr->next;
        }
        ListNode* pre=NULL;
        for(int i=0;i<right-left+1;i++)
        {
            ListNode* next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        leftpre->next->next=curr;
        leftpre->next=pre;
        return dummy->next;
    }
};