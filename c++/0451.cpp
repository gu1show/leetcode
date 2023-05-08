// Link: https://leetcode.com/problems/sort-characters-by-frequency/description/
// The first solution
// Runtime: 34 ms
// Memory: 8.6 MB

class Solution 
{
public:
    std::string frequencySort(const std::string& s) 
    {
        std::unordered_map<char, int> letters;
        for (const char& letter : s)
            letters[letter]++;
        
        std::priority_queue<std::pair<int, char>> sortedByFrequency;
        for (const auto& [key, value] : letters)
            sortedByFrequency.push({value, key});

        std::string result;
        while (!sortedByFrequency.empty()) 
        {
            std::pair<int, char> frequencyAndLetter = sortedByFrequency.top();
            result += std::string(frequencyAndLetter.first, frequencyAndLetter.second);
            sortedByFrequency.pop();
        }

        return result;
    }
};

// The second solution
// Runtime: 8 ms
// Memory: 8.9 MB

class Solution 
{
public:
    std::string frequencySort(const std::string& s) 
    {
        std::vector<std::string> frequency(127);
        for (const char& symbol : s)
            frequency[symbol] += symbol;

        std::sort(frequency.begin(), frequency.end(), [](const std::string& first, const std::string& second) {return first.size() > second.size();});

        std::string result;
        for (const std::string& str : frequency)
            result += str;

        return result;
    }
};
