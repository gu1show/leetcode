// Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
// The first solution
// Runtime: 8 ms 
// Memory: 10.4 MB

class Solution 
{
public:
    int lengthOfLIS(const std::vector<int>& nums) 
    {
        std::vector<int> subsequence(1);
        subsequence[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > subsequence[subsequence.size() - 1]) subsequence.push_back(nums[i]);
            else subsequence[findIndexOfMoreValue(subsequence, nums[i])] = nums[i];
        }
        
        return subsequence.size();
    }
    
private:
    int findIndexOfMoreValue(const std::vector<int>& subsequence, int value)
    {
        int i = 0;
        bool isFound = false;
        while ((i < subsequence.size()) && (!isFound))
        {
            if (subsequence[i] < value) i++;
            else isFound = true;
        }
        
        return i;
    }
};

// The second solution
// Runtime: 262 ms 
// Memory: 10.94 MB

class Solution 
{
public:
    int lengthOfLIS(const std::vector<int>& nums) 
    {
        std::vector<int> lengthOfLIS(nums.size(), 1);
        for (int i = static_cast<int>(nums.size() - 1); i > -1; i--)
            for (int j = i + 1; j < static_cast<int>(nums.size()); j++)
                if (nums[i] < nums[j])
                    lengthOfLIS[i] = std::max(lengthOfLIS[i], lengthOfLIS[j] + 1);

        return *std::max_element(lengthOfLIS.begin(), lengthOfLIS.end());
    }
};
