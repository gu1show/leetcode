// Link: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
// Runtime: 1621 ms
// Memory: 125.1 MB

class Solution 
{
public:
    int numberOfWeakCharacters(std::vector<std::vector<int>>& properties) 
    {
        std::sort(properties.begin(), properties.end(), compareCharacters);
        int numberOfWeak = 0, maximumDefence = properties[0][1];
        for (const auto& character : properties)
            if (character[1] < maximumDefence) numberOfWeak++;
            else maximumDefence = character[1];
        
        return numberOfWeak;
    }
    
private:
    static bool compareCharacters(const std::vector<int>& a, const std::vector<int>& b)
    {
        if (a[0] != b[0]) return a[0] > b[0]; 
        else return a[1] < b[1];
    }
};
