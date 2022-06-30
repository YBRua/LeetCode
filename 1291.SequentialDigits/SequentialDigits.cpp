#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> results;
    int _low;
    int _high;

    bool _is_valid(int value) { return (value >= _low && value <= _high); }

    void _digit_bfs() {
        queue<int> bfsq;
        for (int i = 1; i < 10; ++i) {
            bfsq.push(i);
        }
        while (bfsq.size()) {
            int current = bfsq.front();
            bfsq.pop();

            if (_is_valid(current)) {
                results.push_back(current);
            }

            int next_digit = current % 10 + 1;
            if (next_digit > 9) continue;
            bfsq.push(current * 10 + next_digit);
        }
    }

    void _digit_dfs(int current, int next_digit) {
        /**
         * Works, but it does not output the results in sorted order
         * So we have to use a bfs instead
         */
        if (next_digit > 9) {
            return;
        }
        current = current * 10 + next_digit;
        if (_is_valid(current)) {
            results.push_back(current);
        }
        _digit_dfs(current, next_digit + 1);
        current = current / 10;
        return;
    }

    vector<int> sequentialDigits(int low, int high) {
        this->_low = low;
        this->_high = high;
        results.clear();
        // for (int i = 1; i < 10; ++i) {
        //     _digit_dfs(0, i);
        // }
        _digit_bfs();
        return results;
    }
};

int main() {
    int low = 100;
    int high = 300;
    auto res = Solution().sequentialDigits(low, high);
    for (auto r : res) {
        printf("%d\n", r);
    }
}
