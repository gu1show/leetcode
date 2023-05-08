// Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Runtime: 1070 ms
// Memory: 296.4 MB

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
    ListNode* deleteMiddle(ListNode* head)
    {
        int length = getLength(head);
        if (length > 1)
        {
            removeNode(head, length / 2);
            return head;
        }
        else return nullptr;
    }
    
private:
    int getLength(ListNode* node)
    {
        if (node == nullptr) return 0;
        else return 1 + getLength(node->next);
    }
    
    void removeNode(ListNode* node, int depth)
    {
        if (depth == 1) 
        {
            ListNode* temp = node->next;
            node->next = node->next->next;
            delete temp;
        }
        else removeNode(node->next, depth - 1);
    }
};
