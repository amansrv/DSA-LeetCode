class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {

        ListNode *fast = head;
        ListNode *slow = fast;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
