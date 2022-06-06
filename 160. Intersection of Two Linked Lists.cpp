/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
ListNode *tempA = headA;
ListNode *tempB = headB;

    while(tempA!=NULL)
    {
        len1++;
        tempA=tempA->next;
    }
     while(tempB!=NULL)
    {
        len2++;
        tempB=tempB->next;
    }
    tempA=headA;
    tempB=headB;
    if(len1>len2)
    {
        while(len1!=len2)
        {
            tempA=tempA->next;
            len1--;
        }
    }
    
    else if(len2>len1)
    {
        while(len1!=len2)
        {
            tempB=tempB->next;
            len2--;
        }
    }
    while(tempA!=NULL && tempB!=NULL)
    {
        if(tempA==tempB)
            return tempA;
        tempA=tempA->next;
        tempB=tempB->next;
    }
    
    return NULL;
        
    }
};