// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Runtime: 0 ms
// Memory: 6.5 MB

class Solution 
{
public:
    Solution()
    {
        buttons['2'] = "abc";
        buttons['3'] = "def";
        buttons['4'] = "ghi";
        buttons['5'] = "jkl";
        buttons['6'] = "mno";
        buttons['7'] = "pqrs";
        buttons['8'] = "tuv";
        buttons['9'] = "wxyz";
    }

    std::vector<std::string> letterCombinations(const std::string& digits) 
    {
        if (digits.empty()) return {};

        std::string combination = "";
        addCombinations(digits, combination, 0);

        return combinations;
    }

private:
    std::unordered_map<char, std::string> buttons;
    std::vector<std::string> combinations;

    void addCombinations(const std::string& digits, std::string& combination, int depth)
    {
        if (depth == static_cast<int>(digits.size())) combinations.push_back(combination);
        else
            for (const auto& symbol : buttons[digits[depth]])
            {
                combination.push_back(symbol);
                addCombinations(digits, combination, depth + 1);
                combination.pop_back();
            }
    }
};
