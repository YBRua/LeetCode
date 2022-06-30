#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Item {
   public:
    int idx;
    int val;
    Item() : idx(-1), val(0) {}
    Item(int i, int v) : idx(i), val(v) {}
    friend bool operator>(const Item& a, const Item& b) {
        return a.val > b.val;
    }
};

class Solution {
   public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<Item> sum_vals(aliceValues.size());
        for (int i = 0; i < aliceValues.size(); ++i) {
            sum_vals[i] = Item(i, aliceValues[i] + bobValues[i]);
        }
        int alice_sum = 0;
        int bob_sum = 0;

        sort(sum_vals.begin(), sum_vals.end(), greater<>());

        /**
         * Both Alice and Bob should choose the item
         * with the largest sum of values
         * https://leetcode.com/problems/stone-game-vi/discuss/969817/Strategy-proof 
         */
        for (int i = 0; i < sum_vals.size(); ++i) {
            Item item = sum_vals[i];
            if (i % 2 == 0) {
                alice_sum += aliceValues[item.idx];
            } else {
                bob_sum += bobValues[item.idx];
            }
        }

        if (alice_sum == bob_sum)
            return 0;
        else if (alice_sum > bob_sum)
            return 1;
        else
            return -1;
    }
};
