#include <deque>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int max_profit;

    unordered_map<int, vector<int>> buildUnorderedAdjList(const vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjlist;
        for (const auto& edge : edges) {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }

        return adjlist;
    }

    pair<unordered_map<int, int>, unordered_map<int, vector<int>>> buildParentChildLookups(
        const vector<vector<int>>& edges) {
        const auto adjlist = buildUnorderedAdjList(edges);

        unordered_map<int, int> child2parent;
        unordered_map<int, vector<int>> parent2children;

        // find order
        deque<int> nodelist;
        unordered_set<int> visited;

        nodelist.push_back(0);
        while (!nodelist.empty()) {
            int curr = nodelist.front();
            nodelist.pop_front();
            visited.insert(curr);

            if (adjlist.find(curr) == adjlist.end()) {
                continue;
            }

            for (int next : adjlist.find(curr)->second) {
                if (visited.find(next) != visited.end()) {
                    continue;
                }
                child2parent[next] = curr;
                parent2children[curr].push_back(next);
                nodelist.push_back(next);
            }
        }

        return {child2parent, parent2children};
    }

    unordered_map<int, int> buildBobPath(const unordered_map<int, int>& child2parent, int bob) {
        unordered_map<int, int> bobpath;
        int timestamp = 0;
        while (bob != 0) {
            bobpath[bob] = timestamp++;
            bob = child2parent.find(bob)->second;
        }
        return bobpath;
    }

    void dfsProfitSearch(int alicestamp,
                         int alice,
                         int current_profit,
                         const unordered_map<int, vector<int>>& parent2children,
                         const unordered_map<int, int>& bobpath,
                         vector<int>& profits) {
        int value = profits[alice];
        if (bobpath.find(alice) != bobpath.end()) {
            // bob visits this node also
            int bobstamp = bobpath.find(alice)->second;
            if (bobstamp < alicestamp) {
                // bob visits first, zero
                value = 0;
            } else if (bobstamp == alicestamp) {
                // visits at the same time, share
                value = value / 2;
            }
        }

        current_profit += value;

        if (parent2children.find(alice) != parent2children.end()) {
            // has child
            for (auto next : parent2children.find(alice)->second) {
                dfsProfitSearch(alicestamp + 1, next, current_profit, parent2children, bobpath, profits);
            }
        } else {
            max_profit = max(current_profit, max_profit);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        auto [child2parent, parent2children] = buildParentChildLookups(edges);
        auto bobpath = buildBobPath(child2parent, bob);
        max_profit = numeric_limits<int>::min();
        dfsProfitSearch(0, 0, 0, parent2children, bobpath, amount);

        return max_profit;
    }
};

int main() {
    vector<vector<int>> edges{{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    vector<int> amount{-2, 4, 2, -4, 6};
    int bob = 3;

    int res = Solution().mostProfitablePath(edges, bob, amount);
    cout << res << endl;

    return 0;
}
