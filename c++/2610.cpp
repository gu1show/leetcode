// Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/
// Runtime: 39 ms 
// Memory: 32.03 MB

class Solution 
{
public:
    std::vector<std::vector<int>> findMatrix(const std::vector<int>& nums) 
    {
        std::unordered_map<int, std::unordered_set<int>> tableWithUsedElements;
        std::vector<std::vector<int>> arrayWithConditions;

        for (const auto& val : nums)
        {
            int i = 0;
            bool isFound = false;
            while ((i < tableWithUsedElements.size()) && (!isFound))
            {
                if (tableWithUsedElements[i].find(val) == tableWithUsedElements[i].end())
                    isFound = true;
                i++;
            }

            if (isFound)
            {
                tableWithUsedElements[i - 1].insert(val);
                arrayWithConditions[i - 1].push_back(val);
            }
            else
            {
                tableWithUsedElements[i].insert(val);
                arrayWithConditions.push_back({val});
            }
        }

        return arrayWithConditions;
    }
};
