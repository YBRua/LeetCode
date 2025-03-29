#include <vector>
using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> min_cnts(amount + 1, INT_MAX);
        min_cnts[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0 && min_cnts[i - coin] != INT_MAX) {
                    min_cnts[i] = min(min_cnts[i - coin] + 1, min_cnts[i]);
                }
            }
        }

        return min_cnts[amount] == INT_MAX ? -1 : min_cnts[amount];
    }
};
