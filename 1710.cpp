// Link: https://leetcode.com/problems/maximum-units-on-a-truck/
// Runtime: 82 ms
// Memory: 17.4 MB

class Solution 
{
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize)
    {
        std::sort(boxTypes.begin(), boxTypes.end(), [](const std::vector<int>& vector1, const std::vector<int>& vector2) {return vector1[1] > vector2[1];});
        
        int answer = 0;
        for (auto box : boxTypes)
        {
            answer += std::min(truckSize, box[0]) * box[1];
            truckSize -= std::min(truckSize, box[0]);
        }
        
        return answer;
    }
};
