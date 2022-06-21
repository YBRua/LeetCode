#include <unordered_map>
#include <vector>

using namespace std;

/**
 * return the cheapest price from src to dst with at most k stops. If there is
 * no such route, return -1.
 */

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                      int k) {
    vector<vector<int>> cheapest(n, vector<int>(k + 2, 1919810));  // n, k

    cheapest[src][0] = 0;
    for (int i = 1; i <= k + 1; ++i) {
        // dist[v, i] = min(dist[u, i-1] + cost[u, v] for u, v in edges)
        for (auto f : flights) {
            int s = f[0];
            int d = f[1];
            int cost = f[2];
            int candidate = min(cheapest[d][i - 1], cheapest[d][i]);
            cheapest[d][i] = min(candidate, cheapest[s][i - 1] + cost);
        }
    }

    return cheapest[dst][k + 1] == 1919810 ? -1 : cheapest[dst][k + 1];
}
