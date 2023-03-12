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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        vector<int>v;
       for(int i=0;i<lists.size();i++)
       {
           ListNode*ptr=lists[i];
           while(ptr)
           {
               v.push_back(ptr->val);
               ptr=ptr->next;
           }
       }
       ListNode*dummy=new ListNode(0);
       ListNode *ptr=dummy;
       sort(v.begin(),v.end());
       for(int it:v)
       {
           ListNode *newnode=new ListNode(it);
           newnode->next=NULL;
           dummy->next=newnode;
           dummy=dummy->next;
       }
       return ptr->next;
    }
};