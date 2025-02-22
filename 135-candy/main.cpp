#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> budget(n, 1);

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1] && budget[i] <= budget[i - 1]) {
                budget[i] = budget[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && budget[i] <= budget[i + 1]) {
                budget[i] = budget[i + 1] + 1;
            }
        }

        int sum = 0;
        for (int b : budget) {
            sum += b;
        }

        return sum;
    }
};

int main() {
    auto test = vector<int>{1, 2, 87, 87, 87, 2, 1};
    cout << Solution().candy(test);
}