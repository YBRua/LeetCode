#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

int grouped_knapsack(unordered_map<int, vector<pair<int, int>>> &groups,
                     int capacity) {
    vector<int> dp(capacity + 1, 0);
    for (auto item = groups.begin(); item != groups.end(); ++item) {
        auto g_items = item->second;
        for (int w = capacity; w >= 0; --w) {
            for (int i = 0; i < g_items.size(); ++i) {
                int wi = g_items[i].first;
                int vi = g_items[i].second;
                if (w >= wi) {
                    dp[w] = max(dp[w - wi] + vi, dp[w]);
                }
            }
        }
    }
    return dp[capacity];
}

int main() {
    // group_id -> [weight, value]
    unordered_map<int, vector<pair<int, int>>> groups;
    int capacity;
    int n_items;
    scanf("%d %d", &capacity, &n_items);
    for (int i = 0; i < n_items; ++i) {
        int weight, value, gid;
        scanf("%d %d %d", &weight, &value, &gid);
        groups[gid].push_back(make_pair(weight, value));
    }
    printf("%d\n", grouped_knapsack(groups, capacity));
}
