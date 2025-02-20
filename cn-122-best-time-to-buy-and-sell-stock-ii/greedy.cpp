#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int gain = prices[i] - prices[i - 1];
            profit += gain > 0 ? gain : 0;
        }

        return profit;
    }
};
