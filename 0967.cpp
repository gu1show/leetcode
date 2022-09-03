// Link: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// Runtime: 9 ms
// Memory: 8.8 MB

class Solution
{
public:
    std::vector<int> numsSameConsecDiff(int n, int k) 
    {
        for (int i = 1; i < 10; i++)
            getNumbers(n, k, i, 1);
        
        return numbers;
    }
    
private:
    std::vector<int> numbers;
    
    void getNumbers(int n, int k, int value, int currentLength)
    {
        if ((currentLength == n) && 
            (std::find(numbers.begin(), numbers.end(), value) == numbers.end())) 
            numbers.push_back(value);
        else if (currentLength < n)
        {
            if (value % 10 + k < 10) 
                getNumbers(n, k, value % 10 + k + value * 10, currentLength + 1);
            if (value % 10 - k > -1) 
                getNumbers(n, k, value % 10 - k + value * 10, currentLength + 1);
        }
    }
};
