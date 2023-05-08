// Link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Runtime: 48 ms 
// Memory: 27.5 MB

class Solution 
{
public:
    int findUnsortedSubarray(const std::vector<int>& nums)
    {
        std::vector<int> sorted = nums;
        
        std::sort(sorted.begin(), sorted.end());
        
        int left = 0;
        bool isTheSameLeft = true;
        while ((left < sorted.size()) && (isTheSameLeft))
        {
            if (sorted[left] != nums[left]) isTheSameLeft = false;
            left++;
        }
        if (!isTheSameLeft) left--;
        
        int right = sorted.size() - 1;
        bool isTheSameRight = true;
        while ((right > -1) && (isTheSameRight))
        {
            if (sorted[right] != nums[right]) isTheSameRight = false;
            right--;
        }
        if (!isTheSameRight) right++;
        
        if (right - left <= 0) return 0;
        else return right - left + 1;
    }
};
