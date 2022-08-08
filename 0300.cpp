// Link: https://leetcode.com/problems/longest-increasing-subsequence/
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
