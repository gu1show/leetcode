// Link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Runtime: 123 ms
// Memory: 32.4 MB

class Solution 
{
public:
    int maxArea(int h, int w, std::vector<int>& horizontalCuts, std::vector<int>& verticalCuts) 
    {
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        verticalCuts.insert(verticalCuts.begin(), 0);
        
        for (int i = 0; i < horizontalCuts.size(); i++)
            if (i < horizontalCuts.size() - 1)
                horizontalCuts[i] = horizontalCuts[i + 1] - horizontalCuts[i];
            else horizontalCuts[i] = h - horizontalCuts[i];
        
        for (int i = 0; i < verticalCuts.size(); i++)
            if (i < verticalCuts.size() - 1)
                verticalCuts[i] = verticalCuts[i + 1] - verticalCuts[i];
            else verticalCuts[i] = w - verticalCuts[i];
        
        int maxHeight = *std::max_element(horizontalCuts.begin(), horizontalCuts.end());
        int maxWidth = *std::max_element(verticalCuts.begin(), verticalCuts.end());
        
        return (1LL * maxHeight * maxWidth) % 1000000007;
    }
};
