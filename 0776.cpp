// Link: https://leetcode.com/problems/binary-search/description/
// Runtime: 39 ms
// Memory: 27.5 MB

class Solution 
{
public:
    int search(const std::vector<int>& nums, int target) 
    {
        return binarySearch(0, static_cast<int>(nums.size()), nums, target);
    }

private:
    int binarySearch(int left, int right, const std::vector<int>& nums, int target) 
    {
        if (left >= right) return -1;

        int middle = (left + right) / 2;

        if (nums[middle] == target) return middle;
        else if (nums[middle] < target) return binarySearch(middle + 1, right, nums, target);
        else return binarySearch(left, right - 1, nums, target);
    }
};
