class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;

    while (prev->next && prev->next->next) 
    {
        ListNode* current = prev->next;
        ListNode* next = current->next;

        // Swap positions of two adjacent nodes
        current->next = next->next;
        next->next = current;
        prev->next = next;

        // Move to the next pair
        prev = current;
    }

    ListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
    }
};
