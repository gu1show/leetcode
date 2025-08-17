# Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
# Runtime: 931 ms
# Memory: 51 MB

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        leftNode = head
        for _ in range(k - 1):
            leftNode = leftNode.next

        rightNode, border = head, leftNode.next
        while border is not None:
            rightNode, border = rightNode.next, border.next

        leftNode.val, rightNode.val = rightNode.val, leftNode.val

        return head
