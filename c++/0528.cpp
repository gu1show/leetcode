// Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
// The first solution
// Runtime: 701 ms
// Memory: 190.2 MB

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
  ListNode *swapNodes(ListNode *head, int k) {
    ListNode *iteratorNode = head;
    std::stack<ListNode *> nodes;
    while (iteratorNode != nullptr) {
      nodes.push(iteratorNode);
      iteratorNode = iteratorNode->next;
    }

    ListNode *leftNode = head;
    for (int i = 1; i < k; i++) {
      leftNode = leftNode->next;
      nodes.pop();
    }
    ListNode *rightNode = nodes.top();

    std::swap(leftNode->val, rightNode->val);

    return head;
  }
};

// The second solution
// Runtime: 705 ms
// Memory: 180.1 MB

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
  ListNode *swapNodes(ListNode *head, int k) {
    ListNode *leftNode = head;
    for (int i = 1; i < k; i++)
      leftNode = leftNode->next;

    ListNode *border = leftNode->next, *rightNode = head;
    while (border != nullptr) {
      rightNode = rightNode->next;
      border = border->next;
    }

    std::swap(leftNode->val, rightNode->val);

    return head;
  }
};
