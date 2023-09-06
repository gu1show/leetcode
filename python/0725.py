# Link: https://leetcode.com/problems/split-linked-list-in-parts/description/
# Runtime: 35 ms
# Memory: 16.71 MB

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        head_to_count_length, length_of_list = head, 0
        while head_to_count_length != None:
            length_of_list += 1
            head_to_count_length = head_to_count_length.next
        
        partitioned_list = [None] * k
        length_of_partition, remainder = length_of_list // k, length_of_list % k
        iterator = head
        for i in range(k):
            current_head = iterator
            j = 0
            while (j < length_of_partition + (i < remainder) - 1) and (current_head != None):
                iterator = iterator.next
                j += 1
            
            if iterator != None:
                previous = iterator
                iterator = iterator.next
                previous.next = None
            
            partitioned_list[i] = current_head
        
        return partitioned_list
        