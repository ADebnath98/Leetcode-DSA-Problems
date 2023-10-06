Intuition
An iterative rotation the i element to the front and increment i. Hence we can use the same approach to rotate the array k times.

Approach
Create a dummy node that always points to the head of the sublist to be rotated.
Find the length of the list to know how many rotational iterations we have to do
The outermost loop will guide the number of iterations
set curr and next to the next part of the sublist
Change the curr to point to next->next, and move the pointer of prev to next.
next->next = prev->next and prev->next = next brings next to the head of the list
The above steps iteratively keep bringing node next to the head k-1 times, equalling a rotation of k elements.
Complexity
Time complexity: O(n)
Space complexity: O(n)



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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *curr=head, *prev=dummy, *next;
        int length = 0;
        for(ListNode* temp = head; temp != NULL; temp=temp->next) length++;

        for(int i = 0 ; i < length/k; i++) {
            curr = prev->next;
            next = curr->next;
            for(int j = 0 ; j < k-1; j++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
        }
        return dummy->next;
    }
};