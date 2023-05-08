// Link: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
// Runtime: 81 ms
// Memory: 30 MB

class Solution 
{
public:
    bool isPossible(const std::vector<int>& target) 
    {
        std::priority_queue<int>elements;
        long long sum = 0;
        for (int value : target)
        {
            elements.push(value);
            sum += value;
        }
        
        bool isCorrect = true;
        while ((elements.top() != 1) && (isCorrect))
        {
            sum -= elements.top();
            if ((sum == 0) || (sum >= elements.top())) isCorrect = false;
            if (isCorrect)
            {
                int old = elements.top() % sum;
                if ((old == 0) && (sum != 1)) isCorrect = false;
                sum += old;
                elements.pop();
                elements.push(old);
            }
        }
        
        return isCorrect;
    }
};
