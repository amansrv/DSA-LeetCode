class Solution {
public:
    ListNode* removeElements(ListNode* head, int value) {
        
        
        while(head != NULL && head->val == value){
            head = head->next;
        }
        if(head == NULL)
            return head;
        
        head->next = removeElements(head->next,value);
        return head;
    }
};
