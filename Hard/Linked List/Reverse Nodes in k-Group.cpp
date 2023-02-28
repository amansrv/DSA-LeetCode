class Solution {
public:
    ListNode* reverseKGroup(ListNode* curr, int k) {
        int t=0;
        ListNode* prev=nullptr, *check=curr;
        while(t<k && check!=nullptr) check=check->next,t++;
        if(t<k) return curr;
        while(t-- && curr!=nullptr){
            ListNode* next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        ListNode* tail=prev;
        while( tail!=nullptr && tail->next!=nullptr) tail=tail->next;
        tail->next = curr ? reverseKGroup(curr,k) : nullptr;
        return prev;
    }
};
