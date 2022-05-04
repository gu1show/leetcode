// Link: https://leetcode.com/problems/sort-array-by-parity/
// The first solution
// Runtime: 357 ms
// Memory: 73 MB

class Solution 
{
public:
    int maxOperations(const std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> numbers;
        
        int answer = 0;
        for (auto value : nums)
        {
            if (numbers[k - value] > 0)
            {
                answer++;
                numbers[k - value]--;
            }
            else numbers[value]++;
        }
        
        return answer;
    }
};

// The second solution
// Runtime: 167 ms
// Memory: 58.2 MB

class Solution 
{
public:
    int maxOperations(std::vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        
        int start = 0, finish = nums.size() - 1, answer = 0;
        while(start < finish)
        {
            if (nums[start] + nums[finish] == k)
            {
                start++;
                finish--;
                answer++;
            }
            else if (nums[start] + nums[finish] > k) finish--;
            else start++;
        }
        
        return answer;
    }
};
