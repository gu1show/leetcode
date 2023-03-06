// Link: https://leetcode.com/problems/kth-missing-positive-number/description/
// Runtime: 0 ms
// Memory: 9.7 MB

class Solution 
{
public:
    int findKthPositive(const std::vector<int>& arr, int k) 
    {
        int value = 1, i = 0, number = 0;
        while (number < k) 
        {
            if ((i < static_cast<int>(arr.size())) && (arr[i] > value)) number++;
            else if ((i < static_cast<int>(arr.size())) && (arr[i] == value)) i++;
            else number++;

            value++;
        }

        return value - 1;
    }
};
