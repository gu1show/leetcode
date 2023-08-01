// Link: https://leetcode.com/problems/combinations/description/
// Runtime: 403 ms
// Memory: 164.87 MB

class Solution 
{
public:
    std::vector<std::vector<int>> combine(int n, int k) 
    {
        for (short i = 1; i <= n; i++) range.push_back(i);
        
        addCombination({}, 0, 0, k);
        
        return combinations;
    }

private:
    std::vector<short> range;
    std::vector<std::vector<int>> combinations;

    void addCombination(std::vector<int> combination, int value, int depth, int maxDepth)
    {
        if (depth == maxDepth) combinations.push_back(combination);
        else
            for (int i = value; i < static_cast<int>(range.size()); i++)
            {
                combination.push_back(range[i]);
                addCombination(combination, range[i], depth + 1, maxDepth);
                combination.pop_back();
            }
    }
};
