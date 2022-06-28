#include <cstdio>
#include <vector>

using namespace std;

int knapsack_2d(vector<int>& cost1, vector<int>& cost2, vector<int>& values,
                int capacity1, int capacity2) {
    int n_items = cost1.size();
    // dp: [c1, c2]
    vector<vector<int>> dp(capacity1 + 1, vector<int>(capacity2 + 1, 0));

    // original dp should be of shape [n_items, c1, c2]
    // but since the update at k-th pass only uses results from (k-1)-th pass
    // the outer n_items dim can be optimized
    //// NOTE: In this case we must update dp in the reversed order
    //// or otherwise we may overwrite values from (k-1)-th iteration
    for (int k = 0; k < n_items; ++k) {
        for (int i = capacity1; i >= cost1[k]; --i) {
            for (int j = capacity2; j >= cost2[k]; --j) {
                dp[i][j] =
                    max(dp[i][j], dp[i - cost1[k]][j - cost2[k]] + values[k]);
            }
        }
    }
    return dp[capacity1][capacity2];
}

int main() {
    int n_items;
    int capacity1;
    int capacity2;
    scanf("%d %d %d", &n_items, &capacity1, &capacity2);

    vector<int> costs1(n_items, 0);
    vector<int> costs2(n_items, 0);
    vector<int> values(n_items, 1);
    for (int i = 0; i < n_items; ++i) {
        int cost1, cost2;
        scanf("%d %d", &cost1, &cost2);
        costs1[i] = cost1;
        costs2[i] = cost2;
    }
    printf("%d\n", knapsack_2d(costs1, costs2, values, capacity1, capacity2));
}
