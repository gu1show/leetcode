# Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
# Runtime: 26 ms
# Memory: 16.54 MB

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def __init__(self) -> None:
        self.node_position_to_delete: int = 0

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy_head = ListNode(0, head)
        self.__remove_nth_node(dummy_head, n, 1)

        return dummy_head.next

    def __remove_nth_node(
        self, head: Optional[ListNode], n: int, current_node: int
    ) -> None:
        if head:
            self.__remove_nth_node(head.next, n, current_node + 1)
        else:
            self.node_position_to_delete = current_node - 1 - n

        if current_node == self.node_position_to_delete:
            node_to_delete = head.next
            head.next = node_to_delete.next
            del node_to_delete
