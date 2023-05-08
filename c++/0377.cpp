// Link: https://leetcode.com/problems/combination-sum-iv/
// Runtime: 3 ms
// Memory: 6.6 MB

class Solution 
{
public:
    int combinationSum4(const std::vector<int>& nums, int target)
    {
        std::vector<unsigned int> memorization(target + 1);
        memorization[0] = 1;
        for (int i = 1; i <= target; i++)
            for (const auto& val : nums)
                if (val <= i)
                    memorization[i] += memorization[i - val];
        
        return memorization[target];
    }
};
