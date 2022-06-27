#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Heap, but TLE
// class Solution {
// public:
//     int maxProfit(vector<int>& inventory, int orders) {
//         const int MOD = 1e9 + 7;
//         priority_queue<int, vector<int>> pq(inventory.begin(), inventory.end());
//         long long tot_val = 0;

//         for (long long i = 0; i < orders; ++i) {
//             int val = pq.top(); pq.pop();
//             tot_val = (tot_val + val) % MOD;
//             pq.push(val - 1);
//         }

//         return tot_val % MOD;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int MOD = 1e9 + 7;
        sort(inventory.begin(), inventory.end(), greater<int>());
        long colors = 1;
        long long max_val = 0;
        for (int i = 0; i < inventory.size(); ++i) {
            if (orders < 0) {
                break;
            }
            long curr_counts = inventory[i];
            long next_counts = i < inventory.size() - 1 ? inventory[i+1] : 0;

            // do not take more than is ordered
            // orders / colors is only an option at the final round
            int max_rounds = min(curr_counts - next_counts, orders / colors);
            orders -= colors * max_rounds;

            max_val = (max_val + colors * (curr_counts + (curr_counts - max_rounds + 1)) * max_rounds / 2) % MOD;

            // final round, make up for the missing orders
            // at this time we must have colors > orders
            if (curr_counts - next_counts > max_rounds) {
                max_val = (max_val + orders * (curr_counts - max_rounds)) % MOD;
                break;
            }
            colors ++;
        }
        return max_val;
    }
};
