// Link: https://leetcode.com/problems/minimum-size-subarray-sum/description/
// Runtime: 38 ms
// Memory: 28.1 MB

class Solution 
{
public:
    int minSubArrayLen(int target, const std::vector<int>& nums) 
    {
        int sum = 0, left = 0, minimumSize = static_cast<int>(nums.size());
        bool hasCorrectSum = false;
        for (int right = 0; right < static_cast<int>(nums.size()); right++)
        {
            sum += nums[right];

            while (sum >= target)
            {
                minimumSize = std::min(minimumSize, right - left + 1);
                sum -= nums[left++];
                hasCorrectSum = true;
            }
        }

        if (hasCorrectSum) return minimumSize;
        else return 0;
    }
};
