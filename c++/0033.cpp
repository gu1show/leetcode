// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// The first solution
// Runtime: 0 ms
// Memory: 11 MB

class Solution 
{
public:
    int search(const std::vector<int>& nums, int target) 
    {
        return getIndexOfTarget(nums, target, 0, static_cast<int>(nums.size() - 1));
    }

private:
    int getIndexOfTarget(const std::vector<int>& nums, int target, int left, int right)
    {
        if (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] == target) return middle;
            else if (nums[middle] < target)
            {
                if ((nums[left] <= nums[middle]) || 
                    ((nums[left] > nums[middle]) && (nums[left] > target))) 
                    return getIndexOfTarget(nums, target, middle + 1, right);
                else 
                    return getIndexOfTarget(nums, target, left, middle - 1);
            }
            else
            {
                if (((nums[left] < nums[middle]) && (nums[left] <= target)) || 
                    ((nums[middle] < nums[right]) && (nums[right] > target))) 
                    return getIndexOfTarget(nums, target, left, middle - 1);
                else 
                    return getIndexOfTarget(nums, target, middle + 1, right);
            }
        }
        else return -1;
    }
};

// The second solution
// Runtime: 0 ms
// Memory: 11.1 MB

class Solution 
{
public:
    int search(const std::vector<int>& nums, int target) 
    {
        int left = 0, right = static_cast<int>(nums.size() - 1), indexOfTarget = -1;
        bool isFound = false;
        while ((left <= right) && (!isFound))
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] == target) 
            {
                indexOfTarget = middle;
                isFound = true;
            }
            else if (nums[middle] < target)
            {
                if ((nums[left] <= nums[middle]) || 
                    ((nums[left] > nums[middle]) && (nums[left] > target))) 
                    left = middle + 1;
                else 
                    right = middle - 1;
            }
            else
            {
                if (((nums[left] < nums[middle]) && (nums[left] <= target)) || 
                    ((nums[middle] < nums[right]) && (nums[right] > target))) 
                    right = middle - 1;
                else 
                    left = middle + 1;
            }
        }

        return indexOfTarget;
    }
};
