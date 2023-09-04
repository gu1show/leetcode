# Link: https://leetcode.com/problems/linked-list-cycle/description/
# Runtime: 61 ms
# Memory: 20.31 MB

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast, slow = head, head
        hasCycle = False
        while fast != None and fast.next != None and not hasCycle:
            fast = fast.next.next
            slow = slow.next

            if fast == slow: hasCycle = True

        return hasCycle
