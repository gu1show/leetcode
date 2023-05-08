// Link: https://leetcode.com/problems/guess-number-higher-or-lower/description/
// Runtime: 0 ms
// Memory: 5.9 MB

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution 
{
public:
    int guessNumber(int n) 
    {
        bool isFound = false;
        long left = 1, right = n;
        int guessedNumber = 0;
        while ((!isFound) && (left <= right))
        {
            long middle = (right + left) / 2, direction = guess(middle);
            if (direction == 0) 
            {
                guessedNumber = middle;
                isFound = true;
            }
            else if (direction == -1) right = middle - 1;
            else left = middle + 1;
        }

        return guessedNumber;

        
    }
};
