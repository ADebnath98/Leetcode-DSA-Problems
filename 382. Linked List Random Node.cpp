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
ListNode* head;
int sz = 0 ;
    Solution(ListNode* head) {
        this -> head = head;
        ListNode *temp = head;
        while(temp){
            sz++;
            temp=temp -> next;
        }
    }
    
    int getRandom() {
        double random = static_cast<double>(std::rand()) / RAND_MAX;
        int num = ceil(sz*random);
        ListNode *itr=head;
        for(int i=1;i<num;i++)
            itr=itr->next;
        return itr->val;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */