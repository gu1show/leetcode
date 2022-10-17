// Link: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
// Runtime: 0 ms
// Memory: 6.7 MB

class Solution
{
public:
    bool checkIfPangram(const std::string& sentence) 
    {
        std::unordered_map<char, int> alphabet;
        alphabet['a'] = 0;
        alphabet['b'] = 0;
        alphabet['c'] = 0;
        alphabet['d'] = 0;
        alphabet['e'] = 0;
        alphabet['f'] = 0;
        alphabet['g'] = 0;
        alphabet['h'] = 0;
        alphabet['i'] = 0;
        alphabet['j'] = 0;
        alphabet['k'] = 0;
        alphabet['l'] = 0;
        alphabet['m'] = 0;
        alphabet['n'] = 0;
        alphabet['o'] = 0;
        alphabet['p'] = 0;
        alphabet['q'] = 0;
        alphabet['r'] = 0;
        alphabet['s'] = 0;
        alphabet['t'] = 0;
        alphabet['u'] = 0;
        alphabet['v'] = 0;
        alphabet['w'] = 0;
        alphabet['x'] = 0;
        alphabet['y'] = 0;
        alphabet['z'] = 0;
        
        for (const char& c : sentence) 
            alphabet[c]++;
        
        bool hasAll = true;
        for (const auto& [key, val] : alphabet)
            if (val == 0) 
                hasAll = false;
        
        return hasAll;
    }
};
