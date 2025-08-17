// Link: https://leetcode.com/problems/reverse-linked-list-ii/
// Runtime: 0 ms
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
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *temp = head;
    std::vector<int> list;
    while (temp != nullptr) {
      list.push_back(temp->val);
      temp = temp->next;
    }

    int leftIndex = left - 1, rightIndex = right - 1;
    if (leftIndex < rightIndex) {
      while (leftIndex < rightIndex) {
        std::swap(list[leftIndex], list[rightIndex]);
        leftIndex++;
        rightIndex--;
      }

      ListNode *resultNode = head;
      for (const auto &nodeValue : list) {
        resultNode->val = nodeValue;
        resultNode = resultNode->next;
      }
    }

    return head;
  }
};
