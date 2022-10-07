#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    // constructor
    ListNode(int data)
    {
        this->data = data;
        this->next = next;
    }
};

// Reverse Linked List: Iteration Way
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *nextNode = NULL;
        ListNode *prevNode = NULL;

        while (head)
        {
            head->next = nextNode;
            head->next = prevNode;
            head = prevNode;
            head = nextNode;
        }
        return prevNode;
    }
}

// Reverse Linked List: Recursive Way

