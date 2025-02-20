#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int history_min = 50000;
        int max_profit = -1;

        for (auto price : prices) {
            if (price < history_min) {
                history_min = price;
            }
            int profit = price - history_min;
            if (profit > 0 && profit > max_profit) {
                max_profit = profit;
            }
        }

        return max_profit > 0 ? max_profit : 0;
    }
};
