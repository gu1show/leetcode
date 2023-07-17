// Link: https://leetcode.com/problems/add-two-numbers-ii/description/
// Runtime: 46 ms
// Memory: 73.6 MB

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* list1 = l1, *list2 = l2;
        std::stack<short> valuesList1, valuesList2;
        while (list1 != nullptr)
        {
            valuesList1.push(list1->val);
            list1 = list1->next;
        } 

        while (list2 != nullptr)
        {
            valuesList2.push(list2->val);
            list2 = list2->next;
        }

        ListNode* start = nullptr;
        short totalSum = 0;
        while ((!valuesList1.empty()) || (!valuesList2.empty()))
        {
            if (!valuesList1.empty()) 
            {
                totalSum += valuesList1.top();
                valuesList1.pop();
            }

            if (!valuesList2.empty()) 
            {
                totalSum += valuesList2.top();
                valuesList2.pop();
            }

            ListNode* newNode = new ListNode(totalSum % 10, start);
            start = newNode;
            totalSum /= 10;

            if ((totalSum != 0) && (valuesList1.empty()) && (valuesList2.empty()))
            {
                ListNode* remainderNode = new ListNode(totalSum, start);
                start = remainderNode;
            }
        }

        return start;
    }
};
