class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* prev;
        ListNode* curr;
        prev=head;
        curr=head->next; 
        while(curr!=NULL){
            if(prev->val==curr->val)
            {
                prev->next=curr->next;
            }
            else{
                prev=curr; 
            }
            curr=curr->next;  
        }
        
        return head;
    }
};
