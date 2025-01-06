// Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
// Runtime: 3 ms
// Memory: 12.19 MB

class Solution 
{
public:
    std::vector<int> minOperations(const std::string& boxes) 
    {
        int ballsOnTheLeft = 0, ballsOnTheRight = 0;
        int stepsFromTheLeft = 0, stepsFromTheRight = 0;
        std::vector<int> minimumOperations(boxes.size());
        for (int i = 0; i < static_cast<int>(boxes.size()); i++)
        {
            minimumOperations[i] += stepsFromTheLeft;
            if (boxes[i] == '1')
                ballsOnTheLeft++;
            stepsFromTheLeft += ballsOnTheLeft;

            minimumOperations[boxes.size() - i - 1] += stepsFromTheRight;
            if (boxes[boxes.size() - i - 1] == '1')
                ballsOnTheRight++;
            stepsFromTheRight += ballsOnTheRight;
        }

        return minimumOperations;
    }
};
