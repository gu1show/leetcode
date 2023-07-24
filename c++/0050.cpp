// Link: https://leetcode.com/problems/powx-n/description/
// Runtime: 0 ms
// Memory: 6 MB

class Solution 
{
public:
    double myPow(double x, int n) 
    {
        double product = multiplier(x, std::abs(static_cast<long>(n)));
        if (n >= 0) return product;
        else return 1 / product;
    }

private:
    double multiplier(double x, long n)
    {
        if (n == 0) return 1;
        else if (x == 0) return 0;

        double product = multiplier(x * x, n / 2);

        if (n % 2 == 1) return x * product;
        else return product;
    }
};
