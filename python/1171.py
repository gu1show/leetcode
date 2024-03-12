# Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/
# Runtime: 36 ms
# Memory: 16.98 MB

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy_node = ListNode(0, head)
        current_node = dummy_node
        prefix_sum = 0
        prefix_sum_and_node = {}
        prefix_sum_and_node.update({0: dummy_node})

        while current_node:
            prefix_sum += current_node.val
            prefix_sum_and_node.update({prefix_sum: current_node})
            current_node = current_node.next
        
        prefix_sum = 0
        current_node = dummy_node
        while current_node:
            prefix_sum += current_node.val
            current_node.next = prefix_sum_and_node[prefix_sum].next
            current_node = current_node.next

        return dummy_node.next
