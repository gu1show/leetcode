// Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Runtime: 721 ms
// Memory: 109.1 MB

class Solution 
{
public:
    int findLength(const std::vector<int>& nums1, const std::vector<int>& nums2) 
    {
        std::vector<std::vector<int>> dp(nums1.size(), std::vector<int>(nums2.size()));
        int maxLength = 0;
        
        for (int i = nums1.size() - 1; i > -1; i--)
            for (int j = nums2.size() - 1; j > -1; j--)
                if (nums1[i] == nums2[j])
                {
                    if ((i + 1 < nums1.size()) && (j + 1 < nums2.size()))
                        dp[i][j] = dp[i + 1][j + 1] + 1;
                    else dp[i][j]++;
                    
                    if (maxLength < dp[i][j]) maxLength = dp[i][j];
                }
        
        return maxLength;
    }
};
