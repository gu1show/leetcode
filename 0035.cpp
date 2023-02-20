// Link: https://leetcode.com/problems/search-insert-position/description/
// Runtime: 3 ms
// Memory: 9.7 MB

class Solution 
{
public:
    int searchInsert(const std::vector<int>& nums, int target) 
    {
        return useBinarySearch(nums, 0, nums.size() - 1, target);
    }

private:
    int useBinarySearch(const std::vector<int>& nums, int left, int right, int target) 
    {
        int middle = left + (right - left) / 2;

        if (left > right) return middle;
        else if (nums[middle] == target) return middle;
        else if (nums[middle] > target) return useBinarySearch(nums, left, middle - 1, target);
        else return useBinarySearch(nums, middle + 1, right, target);
    }
};
