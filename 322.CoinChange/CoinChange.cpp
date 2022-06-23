#include <cstdio>
#include <vector>

using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dper(amount + 1, -1);
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] < dper.size()) {
                dper[coins[i]] = 1;
            }
        }
        dper[0] = 0;

        for (int i = 0; i < dper.size(); ++i) {
            int candidate = 1919810;
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0 && dper[i - coins[j]] != -1) {
                    candidate = min(candidate, dper[i - coins[j]] + 1);
                }
            }
            if (candidate != 1919810) {
                dper[i] = candidate;
            }
        }

        return dper[amount];
    }
};

int main() {
    vector<int> inputs({1, 2, 5});
    int amount = 11;
    printf("%d\n", Solution().coinChange(inputs, amount));
}
