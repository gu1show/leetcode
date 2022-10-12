// Link: https://leetcode.com/problems/largest-perimeter-triangle/
// Runtime: 71 ms
// Memory: 21.8 MB

class Solution 
{
public:
    int largestPerimeter(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        
        int max = nums[nums.size() - 1], middle = nums[nums.size() - 2];
        int min = nums[nums.size() - 3], i = static_cast<int>(nums.size() - 4);
        while ((i > -1) && (max >= middle + min))
        {
            max = middle;
            middle = min;
            min = nums[i];
            
            i--;
        }
        
        if (max >= middle + min) return 0;
        else return min + middle + max;
    }
};
