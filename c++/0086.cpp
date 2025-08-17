// Link: https://leetcode.com/problems/partition-list/
// The first solution
// Runtime: 4 ms
// Memory: 10.26 MB

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
  ListNode *partition(ListNode *head, int x) {
    ListNode *headLessX = new ListNode(), *headMoreOrEqualX = new ListNode();
    ListNode *tailLessX = headLessX, *tailMoreOrEqualX = headMoreOrEqualX;

    ListNode *iteratorHead = head;
    while (iteratorHead != nullptr) {
      if (iteratorHead->val < x) {
        tailLessX->next = iteratorHead;
        tailLessX = tailLessX->next;
      } else {
        tailMoreOrEqualX->next = iteratorHead;
        tailMoreOrEqualX = tailMoreOrEqualX->next;
      }

      iteratorHead = iteratorHead->next;
    }

    tailLessX->next = headMoreOrEqualX->next;
    tailMoreOrEqualX->next = nullptr;

    return headLessX->next;
  }
};

// The second solution
// Runtime: 2 ms
// Memory: 10.5 MB

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
  ListNode *partition(ListNode *head, int x) {
    ListNode *headLessX = nullptr, *tailLessX = nullptr;
    ListNode *headMoreOrEqualX = nullptr, *tailMoreOrEqualX = nullptr;

    ListNode *iteratorHead = head;
    while (iteratorHead != nullptr) {
      if ((iteratorHead->val < x) && (headLessX == nullptr))
        headLessX = new ListNode(iteratorHead->val);
      else if ((iteratorHead->val < x) && (headLessX->next == nullptr)) {
        tailLessX = new ListNode(iteratorHead->val);
        headLessX->next = tailLessX;
      } else if (iteratorHead->val < x) {
        tailLessX->next = new ListNode(iteratorHead->val);
        tailLessX = tailLessX->next;
      } else if (headMoreOrEqualX == nullptr)
        headMoreOrEqualX = new ListNode(iteratorHead->val);
      else if (headMoreOrEqualX->next == nullptr) {
        tailMoreOrEqualX = new ListNode(iteratorHead->val);
        headMoreOrEqualX->next = tailMoreOrEqualX;
      } else {
        tailMoreOrEqualX->next = new ListNode(iteratorHead->val);
        tailMoreOrEqualX = tailMoreOrEqualX->next;
      }

      iteratorHead = iteratorHead->next;
    }

    if (headLessX == nullptr)
      return headMoreOrEqualX;
    else if (headLessX->next == nullptr)
      headLessX->next = headMoreOrEqualX;
    else
      tailLessX->next = headMoreOrEqualX;

    return headLessX;
  }
};
