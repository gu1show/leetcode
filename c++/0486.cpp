// Link: https://leetcode.com/problems/predict-the-winner/description/
// Runtime: 3 ms
// Memory: 7.4 MB

class Solution 
{
public:
    bool PredictTheWinner(const std::vector<int>& nums) 
    {
        std::vector<int> scores = nums;
        for (int difference = 1; difference < static_cast<int>(nums.size()); difference++)
            for (int left = 0; left < static_cast<int>(nums.size() - difference); left++)
                scores[left] = std::max(nums[left] - scores[left + 1], nums[left + difference] - scores[left]);

        return scores[0] >= 0;
    }
};
