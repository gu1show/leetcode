// Link: https://leetcode.com/problems/mirror-reflection/
// Runtime: 4 ms
// Memory: 5.6 MB

class Solution 
{
public:
    int mirrorReflection(int p, int q) 
    {
        while (p % 2 == 0 && q % 2 == 0)
        { 
            p /= 2;
            q /= 2;
        }
        
        return 1 - p % 2 + q % 2;    
    }
};
