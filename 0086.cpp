// Link: https://leetcode.com/problems/partition-list/
// Runtime: 9 ms
// Memory: 10.3 MB

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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* less = new ListNode();
        ListNode* moreOrSame = new ListNode();
        ListNode* headLess = less;
        ListNode* headMoreOrSame = moreOrSame;
        
        while (head != nullptr)
            if (head->val < x)
            {
                headLess->next = head;
                headLess = headLess->next;
                head = head->next;
                headLess->next = nullptr;                
            } 
            else
            {
                headMoreOrSame->next = head;
                headMoreOrSame = headMoreOrSame->next;
                head = head->next;
                headMoreOrSame->next = nullptr;
            }
        
        headLess->next = moreOrSame->next;
        return less->next;
    }
};
