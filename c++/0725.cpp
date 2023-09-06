// Link: https://leetcode.com/problems/split-linked-list-in-parts/description/
// Runtime: 9 ms
// Memory: 8.92 MB

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
    std::vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        ListNode* headToCountLength = head;
        int lengthOfList = 0;
        while (headToCountLength != nullptr)
        {
            lengthOfList++;
            headToCountLength = headToCountLength->next;
        }

        std::vector<ListNode*> partitionedList(k);
        ListNode* iterator = head;
        int lengthOfPartition = lengthOfList / k, remainder = lengthOfList % k;
        for (int i = 0; i < k; i++)
        {
            ListNode* currentHead = iterator;
            int j = 0;
            while ((j < lengthOfPartition + (i < remainder) - 1) && (iterator != nullptr))
            {
                iterator = iterator->next;                
                j++;
            }

            if (iterator != nullptr)
            {
                ListNode* previous = iterator;
                iterator = iterator->next;
                previous->next = nullptr;
            }

            partitionedList[i] = currentHead;
        }

        return partitionedList;
    }
};
