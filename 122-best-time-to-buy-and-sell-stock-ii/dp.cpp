#include <vector>

using namespace std;

class Solution {
    int profit[100000][2];

   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        profit[0][0] = 0;
        profit[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            profit[i][0] = max(profit[i - 1][0], profit[i - 1][1] + prices[i]);
            profit[i][1] = max(profit[i - 1][1], profit[i - 1][0] - prices[i]);
        }

        return profit[n - 1][0];
    }
};
