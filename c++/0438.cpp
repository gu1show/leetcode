// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
// Runtime: 16 ms
// Memory: 8.5 MB

class Solution 
{
public:
   std::vector<int> findAnagrams(const std::string& s, const std::string& p) 
   {
        std::vector<int> frequencyP(26), frequencyS(26);
        for (int i = 0; i < static_cast<int>(p.size()); i++)
            frequencyP[p[i] - 'a']++;

        std::vector<int> indexesOfAnagrams;
        int left = 0;
        for (int right = 0; right < static_cast<int>(s.size()); right++) 
        {
            frequencyS[s[right] - 'a']++;
            if (right - left + 1 > static_cast<int>(p.size())) 
            {
                frequencyS[s[left] - 'a']--;
                left++;
            }
            if (frequencyP == frequencyS) indexesOfAnagrams.push_back(left);
        }

        return indexesOfAnagrams;
   }
};
