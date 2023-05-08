// Link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Runtime: 29 ms
// Memory: 13.5 MB

class Solution 
{
public:
    int minPartitions(const std::string n) 
    {
        short max = n[0] - '0';
        for (int i = 1; i < n.size(); i++)
            if (max < n[i] - '0')
                max = n[i] - '0';
        
        return max;
    }
};
