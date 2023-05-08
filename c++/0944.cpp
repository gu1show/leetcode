// Link: https://leetcode.com/problems/delete-columns-to-make-sorted/description/
// Runtime: 66 ms
// Memory: 12.1 MB

class Solution 
{
public:
    int minDeletionSize(const std::vector<std::string>& strs) 
    {
        int numberColumnsToDelete = 0;
        for (int i = 0; i < static_cast<int>(strs[0].size()); i++) 
        {
            bool isSorted = true;
            int j = 1;
            while ((j < static_cast<int>(strs.size())) && (isSorted)) 
            {
                if (strs[j][i] - strs[j - 1][i] < 0) 
                {
                    isSorted = false;
                    numberColumnsToDelete++;
                }

                j++;
            }
        }

        return numberColumnsToDelete;
    }
};
