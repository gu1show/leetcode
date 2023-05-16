// Link: https://leetcode.com/problems/swap-nodes-in-pairs/description/
// Runtime: 3 ms
// Memory: 7.6 MB

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
    ListNode* swapPairs(ListNode* head) 
    {
        if ((head == nullptr) || (head->next == nullptr)) return head;

        ListNode* nodeBeforeList = new ListNode();
        ListNode* previousNode = nodeBeforeList;
        ListNode* currentNode = head;

        while ((currentNode != nullptr) && (currentNode->next != nullptr))
        {
            previousNode->next = currentNode->next;
            currentNode->next = currentNode->next->next;
            previousNode->next->next = currentNode;

            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        return nodeBeforeList->next;
    }
};
