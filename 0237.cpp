// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Runtime: 14 ms
// Memory: 7.5 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    void deleteNode(ListNode* node) 
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
