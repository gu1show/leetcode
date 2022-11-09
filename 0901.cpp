// Link: https://leetcode.com/problems/online-stock-span/description/
// Runtime: 523 ms
// Memory: 84.2 MB

class StockSpanner
{
public:
    int next(int price) 
    {
        int increasing = 1;
        while ((!positions.empty()) && (positions.back().first <= price)) 
        {
            increasing += positions.back().second;
            positions.pop_back();
        }
        positions.push_back(std::make_pair(price, increasing));

        return increasing;
    }

private:
    std::vector<std::pair<int, int>> positions;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
