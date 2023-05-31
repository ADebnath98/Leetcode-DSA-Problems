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
private:
    int howLong(ListNode* head){
        ListNode* temp = head;
        int length = 0;
        if(head == NULL){
            return 0;
        }
        while(temp != NULL){
            length++;
            temp = temp -> next;
        }
        return length;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        if(head -> next == NULL && n == 1){
            return NULL;
        }
        int len = howLong(head);
        int toGo = len - n;
        // cout<<endl<<len<<endl;
        if(len == n){
            head = head -> next;
            return head;
        }
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        // cout<<toGo<<endl;
        while(toGo > 0 && temp != NULL){
            toGo--;
            prev = temp;
            cout<<"Prev is at : "<<prev->val<<" ";
            temp = temp -> next;
            cout<<"Temp is at : "<<temp -> val<<" ";
        }
        prev -> next = temp -> next;
        temp -> next = NULL;

        // nex -> next = NULL;

        return head;
    }
};