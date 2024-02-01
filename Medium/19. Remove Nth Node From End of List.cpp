class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move the fast pointer n steps ahead
    for (int i = 0; i <= n; ++i) 
    {
        if (!fast) 
        {
            // Invalid n (greater than the length of the list)
            delete dummy;
            return head;
        }
        fast = fast->next;
    }

    // Move both pointers until the fast pointer reaches the end
    while (fast) 
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the nth node from the end
    ListNode* toRemove = slow->next;
    slow->next = slow->next->next;
    delete toRemove;

    // Save the new head after removal
    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
    }
};
