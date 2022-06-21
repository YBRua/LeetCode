#include <vector>

using namespace std;


int maxProfit(vector<int>& prices, int fee) {
    int best_hold = 0;
    int best_sell = 0;
    best_hold -= prices[0];
    for (int i = 1; i < prices.size(); ++i) {
        best_hold = max(best_hold, best_sell - prices[i]);
        best_sell = max(best_sell, best_hold + prices[i] - fee);
    }
    return best_sell;
}
