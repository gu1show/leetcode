// Link: https://leetcode.com/problems/jump-game-vi/
// Runtime: 316 ms
// Memory: 90.3 MB

class Solution 
{
public:
    int maxResult(const std::vector<int>& nums, int k)
    {
        int i = nums.size() - 2, maxScore = nums[i + 1];
        std::priority_queue<std::pair<int, int>> priority;
        priority.push({maxScore, i + 1});
        
        while (i > -1)
        {        
            while (priority.top().second - i > k) priority.pop();
            
            int currentScore = nums[i] + priority.top().first;
            priority.push({currentScore, i});
            if (i == 0) maxScore = currentScore;
            i--;
        }
        
        return maxScore;
    }
};
