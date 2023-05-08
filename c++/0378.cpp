// Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Runtime: 52 ms
// Memory: 14.3 MB

class Solution 
{
public:
    int kthSmallest(const std::vector<std::vector<int>>& matrix, int k) 
    {
        std::priority_queue<int> values;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix.size(); j++)
            {
                values.push(matrix[i][j]);
                if (values.size() > k) values.pop();
            }
        
        return values.top();
    }
};
