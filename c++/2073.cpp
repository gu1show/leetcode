// Link: https://leetcode.com/problems/time-needed-to-buy-tickets/description/
// Runtime: 0 ms
// Memory: 9.31 MB

class Solution 
{
public:
    int timeRequiredToBuy(const std::vector<int>& tickets, int k) 
    {
        int totalTime = 0;
        for (int i = 0; i < static_cast<int>(tickets.size()); i++)
            if (i <= k)
                totalTime += std::min(tickets[i], tickets[k]);
            else
                totalTime += std::min(tickets[i], tickets[k] - 1);
        
        return totalTime;
    }
};
