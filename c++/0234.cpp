// Link: https://leetcode.com/problems/palindrome-linked-list/
// Runtime: 371 ms
// Memory: 123.3 MB

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
  bool isPalindrome(ListNode *head) {
    std::vector<short> list;

    while (head != nullptr) {
      list.push_back(head->val);
      head = head->next;
    }

    bool isPalindrome = true;
    int left = 0, right = list.size() - 1;
    while ((left < right) && (isPalindrome)) {
      if (list[left] != list[right])
        isPalindrome = false;
      left++;
      right--;
    }

    return isPalindrome;
  }
};
