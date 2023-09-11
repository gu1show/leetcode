// Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/
// Runtime: 0 ms
// Memory: 13 MB

class Solution 
{
public:
    std::vector<std::vector<int>> groupThePeople(const std::vector<int>& groupSizes) 
    {
        std::unordered_map<int, std::vector<int>> groupSizeAndPeople;
        for (int i = 0; i < static_cast<int>(groupSizes.size()); i++)
            groupSizeAndPeople[groupSizes[i]].push_back(i);
        
        std::vector<std::vector<int>> groups;
        for (auto [key, value] : groupSizeAndPeople)
            while (!value.empty())
            {
                groups.push_back({value.begin(), value.begin() + key});
                value.erase(value.begin(), value.begin() + key);
            }

        return groups;
    }
};
