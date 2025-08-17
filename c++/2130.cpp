// Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
// Runtime: 276 ms
// Memory: 126.7 MB

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
class Solution {
public:
  int pairSum(ListNode *head) {
    std::vector<int> list;
    while (head != nullptr) {
      list.push_back(head->val);
      head = head->next;
    }

    int maxTwinSum = 0;
    for (int i = 0; i < static_cast<int>(list.size() / 2); i++) {
      int twinSum = list[i] + list[list.size() - 1 - i];
      if (maxTwinSum < twinSum)
        maxTwinSum = twinSum;
    }

    return maxTwinSum;
  }
};
