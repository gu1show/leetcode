// Link: https://leetcode.com/problems/valid-anagram/
// Runtime: 18 ms
// Memory: 7.1 MB

class Solution 
{
public:
    bool isAnagram(const std::string& s, const std::string& t) 
    {
        if (s.size() != t.size()) return false;
        else
        {
            std::unordered_map<char, int> letters;
            for (const char& c : s)
                letters[c]++;
        
            bool isAnagram = true;
            for (const char& c: t)
                if ((letters.find(c) != letters.end()) && (letters[c] > 0)) letters[c]--;
                else isAnagram = false;
            
            return isAnagram;   
        }
    }
};
