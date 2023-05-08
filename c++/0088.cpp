// Link: https://leetcode.com/problems/merge-sorted-array/
// Runtime: 8 ms
// Memory: 8.8 MB

class Solution 
{
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {      
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        while((i > -1) && (j > -1))
            if (nums1[i] < nums2[j]) nums1[k--] = nums2[j--];
            else nums1[k--] = nums1[i--];
        
        while (j > -1) nums1[k--] = nums2[j--];
    }
};
