// Link: https://leetcode.com/problems/permutations/description/
// Runtime: 0 ms
// Memory: 8.33 MB

class Solution 
{
public:
    std::vector<vector<int>> permute(const std::vector<int>& nums) 
    {
        addPermutations(nums, {});
        return permutations;
    }

private:
    std::vector<std::vector<int>> permutations;

    void addPermutations(const std::vector<int>& nums, std::vector<int> permutation)
    {
        if (static_cast<int>(permutation.size()) == static_cast<int>(nums.size())) permutations.push_back(permutation);
        else
        {
            for (const auto& val : nums)
            {
                if (std::find(permutation.begin(), permutation.end(), val) == permutation.end())
                {
                    permutation.push_back(val);
                    addPermutations(nums, permutation);
                    permutation.pop_back();
                }
            }
        }
    }
};
