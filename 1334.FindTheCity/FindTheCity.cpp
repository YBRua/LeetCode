#include <cstdio>
#include <vector>

using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dists(n, vector<int>(n, 1919810));
    for (auto e : edges) {
        int src = e[0];
        int dst = e[1];
        int dist = e[2];
        dists[src][dst] = dist;
        dists[dst][src] = dist;
    }

    // Floyd-Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", dists[i][j]);
        }
        printf("\n");
    }

    int candidate = -1;
    int min_val = 1000;
    for (int i = 0; i < n; ++i) {
        int counts = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            if (dists[i][j] <= distanceThreshold) {
                ++counts;
            }
        }
        if (counts <= min_val) {
            candidate = i;
            min_val = counts;
        }
    }

    return candidate;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int threshold = 4;
    printf("%d\n", findTheCity(n, edges, threshold));
}
