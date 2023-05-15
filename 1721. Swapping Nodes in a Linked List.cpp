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
    ListNode* swapNodes(ListNode* head, int k) {
        int c=1;
        ListNode *p=head;
        ListNode *q=head;

        while(c<k){
            c++;
            q=q->next;
        }
        int first_data= q->val;

        while(q->next != NULL){
            p=p->next;
            q=q->next;
        }
        int second_data=p->val;
        p->val=first_data ;

        ListNode *x=head;
        c=1;
        while(c<k){
            c++;
            x=x->next ;
        }
        x->val=second_data ;

        return head;
    }
};