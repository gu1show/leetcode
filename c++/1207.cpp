// Link: https://leetcode.com/problems/unique-number-of-occurrences/description/
// Runtime: 3 ms
// Memory: 8.2 MB

class Solution 
{
public:
    bool uniqueOccurrences(const std::vector<int>& arr) 
    {
        for (const int& val : arr)
            numberOccurrences[val]++;

        for (const auto& [key, val] : numberOccurrences)
            if (occurrences.find(val) == occurrences.end()) occurrences.insert(val);
            else return false;

        return true;
    }

private:
    std::unordered_map<int, int> numberOccurrences;
    std::set<int> occurrences;
};
