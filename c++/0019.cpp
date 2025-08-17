// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Runtime: 0 ms
// Memory: 13.36 MB

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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int nodePositionToDelete = 0;
    ListNode *dummyHead = new ListNode(0, head);
    removeNthNode(dummyHead, n, 1, nodePositionToDelete);

    return dummyHead->next;
  }

private:
  void removeNthNode(ListNode *head, int n, int currentNode,
                     int &nodePositionToDelete) {
    if (head != nullptr)
      removeNthNode(head->next, n, currentNode + 1, nodePositionToDelete);
    else
      nodePositionToDelete = currentNode - 1 - n;

    if (currentNode == nodePositionToDelete) {
      ListNode *nodeToDelete = head->next;
      head->next = nodeToDelete->next;
      delete nodeToDelete;
    }
  }
};
