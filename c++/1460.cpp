// Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/
// Runtime: 12 ms
// Memory: 21.02 MB

class Solution 
{
public:
    bool canBeEqual(const std::vector<int>& target, const std::vector<int>& arr) 
    {
        return createValueAndFrequencyUnorderedMap(target) == createValueAndFrequencyUnorderedMap(arr);
    }

private:
    std::unordered_map<int, int> createValueAndFrequencyUnorderedMap(const std::vector<int>& arr)
    {
        std::unordered_map<int, int> valueAndFrequency;
        for (const auto& val : arr)
            valueAndFrequency[val]++;
        
        return valueAndFrequency;
    }
};
