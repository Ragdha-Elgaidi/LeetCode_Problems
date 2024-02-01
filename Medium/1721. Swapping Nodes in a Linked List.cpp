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
class Solution 
{
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
    // Step 1: Traverse to find the length of the linked list (n)
    int n = 0;
    ListNode* current = head;
    
    while (current) 
    {
        n++;
        current = current->next;
    }

    // Calculate the position of the kth node from the end
    int kthFromEnd = n - k + 1;

    // Step 2: Traverse again to swap the values of the kth nodes
    ListNode* firstK = nullptr;
    ListNode* secondK = nullptr;
    current = head;

    for (int i = 1; i <= n; i++) 
    {
        if (i == k) 
        {
            firstK = current;
        }

        if (i == kthFromEnd) 
        {
            secondK = current;
        }

        current = current->next;
    }

    // Swap the values
    int temp = firstK->val;
    firstK->val = secondK->val;
    secondK->val = temp;

    return head;
    }
};
