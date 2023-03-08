// Link: https://leetcode.com/problems/koko-eating-bananas/description/
// Runtime: 42 ms
// Memory: 18.9 MB

class Solution 
{
public:
    int minEatingSpeed(const std::vector<int>& piles, int h) 
    {
        int right = *std::max_element(piles.begin(), piles.end());
        if (piles.size() == h) return right;

        int left = 1;
        while (left <= right) 
        {
            int middle = left + (right - left) / 2;
            
            if (canEatAll(piles, middle, h)) right = middle - 1;
            else left = middle + 1;
        }

        return left;
    }

private:
    bool canEatAll(const std::vector<int>& piles, int speed, int maxTime) 
    {
        int hours = 0;
        for (const auto& pile : piles) 
        {
            hours += (pile - 1) / speed + 1;
            if (hours > maxTime) return false;
        }

        return true;
    }
};
