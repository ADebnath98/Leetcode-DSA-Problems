class Solution {
    private: int getLength (ListNode* head) {
        int len = 0;
        while(head) {
            len++;
            head = head -> next;
        }
        return len;
    }

public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int len = getLength(head);
        vector<ListNode*> ans(k);
        int ind = 0;
        
        while(head) {

            int size = (len + k - 1) / k;
            len -= size;
            k--;

            ans[ind++] = head;

            while(--size) {
                head = head->next;
            }

            ListNode* nxt = head->next;
            head->next = NULL;
            head = nxt;

        }

        return ans;

    }
};