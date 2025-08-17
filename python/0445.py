# Link: https://leetcode.com/problems/add-two-numbers-ii/description/
# Runtime: 87 ms
# Memory: 16.5 MB

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        list1, list2 = l1, l2
        stack_for_list1, stack_for_list2 = [], []
        while list1 is not None:
            stack_for_list1.append(list1.val)
            list1 = list1.next

        while list2 is not None:
            stack_for_list2.append(list2.val)
            list2 = list2.next

        start = None
        total_sum = 0
        while (len(stack_for_list1) > 0) or (len(stack_for_list2) > 0):
            if len(stack_for_list1) > 0:
                total_sum += stack_for_list1.pop()

            if len(stack_for_list2) > 0:
                total_sum += stack_for_list2.pop()

            new_node = ListNode(total_sum % 10, start)
            total_sum //= 10
            start = new_node

            if (
                (len(stack_for_list1) == 0)
                and (len(stack_for_list2) == 0)
                and (total_sum != 0)
            ):
                last_node = ListNode(total_sum, start)
                start = last_node

        return start
