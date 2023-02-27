class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        auto ans = head->next;
        auto next = head->next->next;
        head->next->next = head;
        head->next = swapPairs(next);
        return ans;
    }
};
