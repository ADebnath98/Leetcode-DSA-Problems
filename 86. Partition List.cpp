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
    void insertAtTail(ListNode* &head , ListNode* &tail , int data){
        ListNode *temp = new ListNode(data);
        if(head == NULL){
            head = temp;
            tail = temp;
            tail->next = NULL;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        return;
    }

    void insertAtHead(ListNode* &head , ListNode* &tail , int data){
        ListNode *temp = new ListNode(data);
        if(head == NULL){
            head = temp;
            tail = temp;
            tail->next = NULL;
        }
        else{
            temp->next = head;
            head = temp;
        }
        return;
    }

    void reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* frwd = NULL;

        while(curr != NULL){
            frwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frwd;
        }
        head = prev;
    }

    ListNode* partition(ListNode* head, int x) {
        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        ListNode *temp = head;
        while(temp != NULL){
            if(temp->val >= x){
                insertAtTail(newHead , newTail , temp->val);
            }
            temp = temp->next;            
        }

        reverse(head);

        temp = head;
        while(temp != NULL){
            if(temp->val < x){
                insertAtHead(newHead , newTail , temp->val);
            }
            temp = temp->next;
        }
        return newHead;
    }
};