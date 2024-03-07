// Link: https://leetcode.com/problems/middle-of-the-linked-list/description/
// Runtime: 0 ms
// Memory: 8.66 MB

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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* root = head;
        std::vector<ListNode*> nodes;
        while (root != nullptr)
        {
            nodes.push_back(root);
            root = root->next;
        }

        return nodes[nodes.size() / 2];
    }
};
