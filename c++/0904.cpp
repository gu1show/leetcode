// Link: https://leetcode.com/problems/fruit-into-baskets/description/
// Runtime: 182 ms
// Memory: 71.2 MB

class Solution 
{
public:
    int totalFruit(const std::vector<int>& fruits) 
    {
        std::unordered_map<int, int> fruitsFrequency;
        
        int left = 0, numberFruits = 0;
        for (int right = 0; right < static_cast<int>(fruits.size()); right++) 
        {
            fruitsFrequency[fruits[right]]++;
            
            if (fruitsFrequency.size() <= 2) numberFruits = std::max(numberFruits, right - left + 1);
            else
            {
                fruitsFrequency[fruits[left]]--;

                if (fruitsFrequency[fruits[left]] == 0) fruitsFrequency.erase(fruits[left]);
                left++;
            }
        }

        return numberFruits;
    }
};
