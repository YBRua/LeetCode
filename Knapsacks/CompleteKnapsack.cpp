#include <cstdio>
#include <vector>

using namespace std;

long long complete_knapsack(vector<long long>& weights, vector<long long>& values, long long capacity) {
    long long n_items = weights.size();
    vector<long long> dp(capacity + 1, 0);
    for (long long i = 0; i <= capacity; ++i) {
        for (long long k = 0; k < n_items; ++k) {
            if (i - weights[k] >= 0) {
                dp[i] = max(dp[i - weights[k]] + values[k], dp[i]);
            }
        }
    }

    return dp[capacity];
}

int main() {
    long long n_items;
    long long capacity;
    scanf("%lld %lld", &capacity, &n_items);
    vector<long long> weights(n_items, 0);
    vector<long long> values(n_items, 0);
    for (long long i = 0; i < n_items; ++i) {
        long long weight, value;
        scanf("%lld %lld", &weight, &value);
        weights.push_back(weight);
        values.push_back(value);
    }
    printf("%lld\n", complete_knapsack(weights, values, capacity));
}
