// Link: https://leetcode.com/problems/search-a-2d-matrix/description/
// The first solution
// Runtime: 3 ms
// Memory: 9.6 MB

class Solution 
{
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) 
    {
        return canFoundValue(matrix, target, 0, static_cast<int>(matrix[0].size() * matrix.size() - 1));
    }

private:
    bool canFoundValue(const std::vector<std::vector<int>>& matrix, int target, int left, int right)
    {
        if (left <= right)
        {
            int middle = left + (right - left) / 2;
            int chosenValue = matrix[middle / matrix[0].size()][middle % matrix[0].size()];
            if (chosenValue == target) return true;
            else if (chosenValue > target) return canFoundValue(matrix, target, left, middle - 1);
            else return canFoundValue(matrix, target, middle + 1, right);
        }
        else return false;
    }
};

// The second solution
// Runtime: 0 ms
// Memory: 9.4 MB

class Solution 
{
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) 
    {
        int left = 0, right = static_cast<int>(matrix.size() * matrix[0].size() - 1);
        bool isFound = false;
        while ((left <= right) && (!isFound))
        {
            int middle = left + (right - left) / 2;
            int chosenValue = matrix[middle / matrix[0].size()][middle % matrix[0].size()];

            if (chosenValue == target) isFound = true;
            else if (chosenValue > target) right = middle - 1;
            else left = middle + 1;
        }

        return isFound;
    }
};
