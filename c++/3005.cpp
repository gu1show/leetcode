// Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/
// Runtime: 7 ms
// Memory: 22.92 MB

class Solution 
{
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        std::unordered_map<int, int> elementAndFrequency;
        int count = 0, maxFrequency = 0;
        for (const auto& val : nums)
        {
            elementAndFrequency[val]++;

            if (elementAndFrequency[val] > maxFrequency)
            {
                maxFrequency = elementAndFrequency[val];
                count = 1;
            }
            else if (elementAndFrequency[val] == maxFrequency)
                count++;
        }

        return count * maxFrequency;
    }
};
