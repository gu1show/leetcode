// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Runtime: 4 ms
// Memory: 13.7 MB

class Solution 
{
public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target) 
    {
        std::vector<int> borders(2, -1);
        int index = returnIndexOfValue(nums, 0, nums.size() - 1, target);
        
        if (index != -1)
        {
            int i = index, j = index;
            while (((i > -1) && (nums[i] == target)) || 
                   ((j < nums.size())) && (nums[j] == target))
            {
                if ((i > -1) && (nums[i] == target)) i--;
                if ((j < nums.size()) && (nums[j] == target)) j++;
            }
            
            borders[0] = i + 1;
            borders[1] = j - 1;
        }
        
        return borders;
    }
    
private:
    int returnIndexOfValue(const std::vector<int>& nums, int left, int right, int target)
    {
        if (left > right) return -1;
        else
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) return middle;
            else if (nums[middle] < target) return returnIndexOfValue(nums, middle + 1, right, target);
            else return returnIndexOfValue(nums, left, middle - 1, target);
        }
    }
};
