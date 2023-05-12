// Link: https://leetcode.com/problems/solving-questions-with-brainpower/description/
// Runtime: 376 ms
// Memory: 115.2 MB

class Solution 
{
public:
    long long mostPoints(const std::vector<std::vector<int>>& questions) 
    {
        int numberOfQuestions = static_cast<int>(questions.size());
        std::vector<long long> ways(numberOfQuestions + 1);
        for (int i = numberOfQuestions - 1; i > -1; i--)
        {
            int point = questions[i][0];
            int brainpower = questions[i][1];

            int nextPosition = std::min(numberOfQuestions, i + brainpower + 1);
            ways[i] = std::max(ways[i + 1], point + ways[nextPosition]);
        }

        return ways[0];
    }
};
