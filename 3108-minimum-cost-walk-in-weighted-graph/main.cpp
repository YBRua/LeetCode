#include <iostream>
#include <vector>
using namespace std;

// 3108-minimum-cost-walk-in-weighted-graph
class Solution {
    class UnionFind {
       public:
        vector<int> parents;
        vector<int> weights;

        UnionFind(int n) {
            parents.resize(n);
            weights.resize(n);
            for (int i = 0; i < n; i++) {
                parents[i] = i;
                weights[i] = -1;
            }
        }

        int find(int x) {
            if (parents[x] != x) {
                int root = find(parents[x]);
                parents[x] = root;
            }
            return parents[x];
        }

        void join(int x, int y, int w) {
            int px = find(x);
            int py = find(y);

            weights[py] &= w;

            if (px != py) {
                parents[px] = py;
                weights[py] &= weights[px];
            }
        }
    };

   public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        auto dsu = UnionFind(n);
        for (auto edge : edges) {
            int src = edge[0], dst = edge[1], w = edge[2];
            dsu.join(src, dst, w);
        }

        vector<int> res;

        for (auto q : query) {
            int src = q[0], dst = q[1];
            int ps = dsu.find(src), pd = dsu.find(dst);

            if (ps != pd) {
                res.push_back(-1);
            } else {
                res.push_back(dsu.weights[ps]);
            }
        }

        return res;
    }
};

int main() {
    int n = 6;
    auto edges = vector<vector<int>>{{4, 0, 3}};
    auto query = vector<vector<int>>{{4, 0}};

    auto sol = Solution();
    auto res = sol.minimumCost(n, edges, query);
}