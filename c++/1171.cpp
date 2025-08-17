// Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
// Runtime: 4 ms
// Memory: 15.12 MB

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
  ListNode *removeZeroSumSublists(ListNode *head) {
    ListNode *dummyNode = new ListNode(0, head);
    ListNode *currentNode = dummyNode;
    int prefixSum = 0;
    std::unordered_map<int, ListNode *> prefixSumAndNode;
    prefixSumAndNode[0] = dummyNode;
    while (currentNode != nullptr) {
      prefixSum += currentNode->val;
      prefixSumAndNode[prefixSum] = currentNode;
      currentNode = currentNode->next;
    }

    prefixSum = 0;
    currentNode = dummyNode;
    while (currentNode != nullptr) {
      prefixSum += currentNode->val;
      currentNode->next = prefixSumAndNode[prefixSum]->next;
      currentNode = currentNode->next;
    }

    return dummyNode->next;
  }
};
