// Link: https://leetcode.com/problems/strange-printer/description/
// Runtime: 128 ms
// Memory: 9.4 MB

class Solution 
{
public:
    int strangePrinter(const std::string& s) 
    {
        std::vector<std::vector<int>> segmentsChanging(s.size(), std::vector<int>(s.size(), s.size()));
        for (int length = 1; length <= static_cast<int>(s.size()); length++)
        {
            for (int left = 0; left <= static_cast<int>(s.size() - length); left++)
            {
                int right = left + length - 1;
                int j = -1;
                for (int i = left; i < right; i++)
                {
                    if ((s[i] != s[right]) && (j == -1)) j = i;

                    if (j != -1) 
                        segmentsChanging[left][right] = std::min(segmentsChanging[left][right], 1 + segmentsChanging[j][i] + segmentsChanging[i + 1][right]);
                }

                if (j == -1) segmentsChanging[left][right] = 0;
            }
        }

        return 1 + segmentsChanging[0][static_cast<int>(s.size() - 1)];
    }
};
