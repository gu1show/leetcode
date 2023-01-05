// Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
// Runtime: 534 ms
// Memory: 110 MB

class Solution 
{
public:
    int findMinArrowShots(const std::vector<std::vector<int>>& points) 
    {
        std::vector<std::vector<int>> balloons = points;
        std::sort(balloons.begin(), balloons.end());

        int shots = 1, rightBoard = balloons[0][1];
        for (const auto& balloon : balloons) 
        {
            if (balloon[0] > rightBoard) 
            {
                rightBoard = balloon[1];
                shots++;
            }
            rightBoard = std::min(rightBoard, balloon[1]);
        }

        return shots;
    }
};
