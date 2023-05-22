// Link: https://leetcode.com/problems/top-k-frequent-elements/description/
// Runtime: 14 ms
// Memory: 13.6 MB

class Solution 
{
public:
    std::vector<int> topKFrequent(const std::vector<int>& nums, int k) 
    {
        std::unordered_map<int, int> frequencies;
        for (const auto& val : nums)
            frequencies[val]++;
        
        std::vector<std::pair<int, int>> topKPairs(k);
        std::partial_sort_copy(frequencies.begin(),
                               frequencies.end(),
                               topKPairs.begin(),
                               topKPairs.end(),
                               [](const std::pair<int, int>& a, 
                                  const std::pair<int, int>& b)
                               { return a.second > b.second; });
        
        std::vector<int> topKValues;
        for (const auto& pair : topKPairs)
            topKValues.push_back(pair.first);

        return topKValues;
    }
};
