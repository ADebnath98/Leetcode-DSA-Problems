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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head || !head->next)        // if head is null or head's next null we will return head
        return head;
    
    ListNode* odd = head;             // we are taking three pointer 
    ListNode* even = head->next;
    ListNode* even_start = head->next;     // this pointer is used when we will join the last link 
    
    while(even && even->next)         // while even or even's next not null we will run the loop
    {
        odd->next = even->next;         // joining the alternate links and then updating thier postions 
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = even_start;        
    
    return head;
}
};