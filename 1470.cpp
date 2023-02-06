// Link: https://leetcode.com/problems/shuffle-the-array/description/
// The first solution
// Runtime: 4 ms
// Memory: 10 MB

class Solution 
{
public:
    std::vector<int> shuffle(const std::vector<int>& nums, int n) 
    {
        std::vector<bool> isVisited(nums.size());
        for (int i = 0; i < static_cast<int>(nums.size()); i++) 
        {
            if (!isVisited[i]) 
            {
                addElement(nums[i], isVisited, i);

                if (i + n < nums.size()) addElement(nums[i + n], isVisited, i + n);
            }
        }

        return shuffledArray;
    }

private:
    std::vector<int> shuffledArray;

    void addElement(int element, std::vector<bool>& isVisited, int index) 
    {
        shuffledArray.push_back(element);
        isVisited[index] = true;
    }
};

// The second solution
// Runtime: 0 ms
// Memory: 9.8 MB

class Solution 
{
public:
    std::vector<int> shuffle(const std::vector<int>& nums, int n) 
    {
        std::vector<int> shuffledArray;
        
        for (int i = 0; i < n; i++) 
        {
            shuffledArray.push_back(nums[i]);
            shuffledArray.push_back(nums[i + n]);
        }

        return shuffledArray;
    }
};
