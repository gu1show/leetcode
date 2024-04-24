// Link: https://leetcode.com/problems/n-th-tribonacci-number/description/
// Runtime: 3 ms
// Memory: 7.53 MB

class Solution 
{
public:
    int tribonacci(int n) 
    {
        std::unordered_map<int, int> numberAndValue;
        numberAndValue[0] = 0;
        numberAndValue[1] = 1;
        numberAndValue[2] = 1;

        for (int i = 3; i <= n; i++)
            numberAndValue[i] = numberAndValue[i - 1] + numberAndValue[i - 2] + numberAndValue[i - 3];
        
        return numberAndValue[n];
    }
};
