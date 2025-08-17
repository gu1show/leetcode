# Link: https://leetcode.com/problems/swap-nodes-in-pairs/description/
# Runtime: 40 ms
# Memory: 16.3 MB

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        node = head.next
        head.next = self.swapPairs(head.next.next)
        node.next = head

        return node
