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
     ListNode* reverse(ListNode* slow){
         ListNode* prev = NULL;
         while(slow){
             ListNode*temp = slow->next;
             slow->next = prev ;
             prev = slow ;
             slow = temp;
         }
         return prev ;
     }
    int pairSum(ListNode* head) {
        if(head->next->next==NULL)return head->val+head->next->val;
        ListNode*fast = head;
        ListNode*slow = head;
        int sum = -1;
        while(fast && fast->next->next){
           slow = slow->next;
           fast = fast->next->next;
        }
        slow = reverse(slow->next);
        fast = head;
        while(slow){
            int x  = slow->val+fast->val;
            sum = max(x,sum);
            slow = slow->next;
            fast = fast->next;
        }
        return sum;
    }
};