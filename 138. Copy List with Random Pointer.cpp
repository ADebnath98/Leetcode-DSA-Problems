class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        map<Node*, Node*> mpp;
        Node* curnt = head;
        Node* previous = NULL;
        Node* newHead = NULL;
        while(curnt) {
            Node* temp = new Node(curnt->val);
            mpp[curnt] = temp;
            if(newHead == NULL) {
                newHead = temp;
                previous = newHead;
            } else {
                previous->next = temp;
                previous = temp;
            }
            curnt = curnt->next;
        }
        
        curnt = head;
        Node* newCurr = newHead;
        while(curnt) {
            if(curnt->random == NULL) {
                newCurr->random = NULL;
            } else {
                newCurr->random = mpp[curnt->random];
            }
            
            newCurr = newCurr->next;
            curnt = curnt->next;
        }
        return newHead;  
    }
};