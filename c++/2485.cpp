// Link: https://leetcode.com/problems/find-the-pivot-integer/description/
// Runtime: 3 ms
// Memory: 7.16 MB

class Solution 
{
public:
    int pivotInteger(const int n) 
    {
        int sumFrom1ToN = n * (1 + n) / 2;
        int potentialPivot = std::sqrt(sumFrom1ToN);

        if (potentialPivot * potentialPivot == sumFrom1ToN)
            return potentialPivot;
        else
            return -1;
    }
};
