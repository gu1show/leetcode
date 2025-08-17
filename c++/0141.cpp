// Link: https://leetcode.com/problems/linked-list-cycle/description/
// Runtime: 7 ms
// Memory: 8.11 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    bool hasCycle = false;
    while ((fast != nullptr) && (fast->next != nullptr) && (!hasCycle)) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow)
        hasCycle = true;
    }

    return hasCycle;
  }
};
