# Link: https://leetcode.com/problems/partition-list/description/
# The first solution
# Runtime: 43 ms
# Memory: 16.49 MB

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        head_less_x, tail_less_x = None, None
        head_more_or_equal_x, tail_more_or_equal_x = None, None

        iterator_head = head
        while iterator_head is not None:
            if (iterator_head.val < x) and (head_less_x is None):
                head_less_x = ListNode(iterator_head.val)
            elif (iterator_head.val < x) and (head_less_x.next is None):
                tail_less_x = ListNode(iterator_head.val)
                head_less_x.next = tail_less_x
            elif iterator_head.val < x:
                tail_less_x.next = ListNode(iterator_head.val)
                tail_less_x = tail_less_x.next
            elif head_more_or_equal_x is None:
                head_more_or_equal_x = ListNode(iterator_head.val)
            elif head_more_or_equal_x.next is None:
                tail_more_or_equal_x = ListNode(iterator_head.val)
                head_more_or_equal_x.next = tail_more_or_equal_x
            else:
                tail_more_or_equal_x.next = ListNode(iterator_head.val)
                tail_more_or_equal_x = tail_more_or_equal_x.next

            iterator_head = iterator_head.next

        if head_less_x is None:
            return head_more_or_equal_x
        elif head_less_x.next is None:
            head_less_x.next = head_more_or_equal_x
        else:
            tail_less_x.next = head_more_or_equal_x

        return head_less_x


# The second solution
# Runtime: 37 ms
# Memory: 16.14 MB


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        head_less, head_more_or_equal = ListNode(), ListNode()
        tail_less, tail_more_or_equal = head_less, head_more_or_equal

        iterator_head = head
        while iterator_head is not None:
            if iterator_head.val < x:
                tail_less.next = iterator_head
                tail_less = tail_less.next
            else:
                tail_more_or_equal.next = iterator_head
                tail_more_or_equal = tail_more_or_equal.next

            iterator_head = iterator_head.next

        tail_less.next = head_more_or_equal.next
        tail_more_or_equal.next = None

        return head_less.next
