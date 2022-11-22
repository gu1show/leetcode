// Link: https://leetcode.com/problems/perfect-squares/description/
// Runtime: 3 ms
// Memory: 6 MB

class Solution 
{
public:
    int numSquares(int n) 
    {
        if ((int)floor(sqrt(n)) * (int)floor(sqrt(n)) == n) return 1;
        else if (isTwoPerfectSquareNumbers(n)) return 2;
        else if (isThreePerfectSquareNumbers(n)) return 3;
        else return 4;
    }

private:
    bool isTwoPerfectSquareNumbers(int n) 
    {
        int i = 1;
        bool isFound = false;
        while ((i < sqrt(n)) && (!isFound))
        {
            if (n - i * i == pow((int)floor(sqrt(n - i * i)), 2)) isFound = true;
            i++;
        }

        return isFound;
    }

    bool isThreePerfectSquareNumbers(int n) 
    {
        while (n % 4 == 0) n /= 4;

        if (n % 8 != 7) return true;
        else return false;
    }
};
