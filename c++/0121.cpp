// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Runtime: 127 ms
// Memory: 93.3 MB

class Solution {
public:
  int maxProfit(const std::vector<int> &prices) {
    int priceForBuying = prices[0], profit = 0;
    for (const int &price : prices) {
      if (price < priceForBuying)
        priceForBuying = price;
      if (profit < price - priceForBuying)
        profit = price - priceForBuying;
    }

    return profit;
  }
};
