// Link: https://leetcode.com/problems/minimum-time-to-complete-trips/description/
// Runtime: 473 ms
// Memory: 94.3 MB

class Solution 
{
public:
    long long minimumTime(const std::vector<int>& time, int totalTrips) 
    {
        long long left = 0, right = LONG_MAX;
        while (left <= right) 
        {
            unsigned long long trips = 0, middle = left + (right - left) / 2;
            for (const auto& element : time) trips += middle / element;
            
            if (trips < totalTrips) left = middle + 1;
            else right = middle - 1;
        }

        return left;
    }
};
