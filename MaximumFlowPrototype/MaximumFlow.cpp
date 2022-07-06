#include <queue>
#include <unordered_set>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

bool _flow_bfs(vector<vector<int>>& aug_graph, vector<int>& prev, int src,
               int dst) {
    queue<int> bfsq;
    unordered_set<int> visited;
    // we use prev to track the path from sink to source
    prev.clear();
    prev.resize(aug_graph.size(), -1);

    bfsq.push(src);
    while (bfsq.size()) {
        int next = bfsq.front();
        bfsq.pop();
        if (visited.count(next)) continue;
        visited.emplace(next);

        if (next == dst) return true;

        for (int i = 0; i < aug_graph[next].size(); ++i) {
            if (!visited.count(i) && aug_graph[next][i] > 0) {
                bfsq.push(i);
                prev[i] = next;
            }
        }
    }
    return false;
}

void _augment(vector<vector<int>>& aug_graph, vector<int>& prev, int dst) {
    int bottleneck = INT_MAX;
    int current = dst;
    int pre = prev[dst];

    // find the maximum flow we can push
    // i.e. find the minimum capacity along the path
    while (pre != -1) {
        bottleneck = min(bottleneck, aug_graph[pre][current]);
        current = pre;
        pre = prev[current];
    }

    // update the augmented graph
    current = dst;
    pre = prev[dst];
    while (pre != -1) {
        aug_graph[pre][current] -= bottleneck;
        aug_graph[current][pre] += bottleneck;
        current = pre;
        pre = prev[current];
    }
}

// The Edmonds-Karp Maximum Flow Algorithm
int maximum_flow(vector<vector<int>>& aug_graph, int src, int dst) {
    vector<int> prev;
    while (_flow_bfs(aug_graph, prev, src, dst)) {
        _augment(aug_graph, prev, dst);
    }
    int max_flow = 0;
    for (int i = 0; i < aug_graph.size(); ++i) {
        // max_flow == sum of flows into source in the augmented graph
        max_flow += aug_graph[i][src];
    }
    return max_flow;
}

int main() {
    int n_nodes = 0, n_edges = 0;
    int src = 0, dst = 0;
    cin >> n_nodes >> n_edges;
    cin >> src >> dst;
    vector<vector<int>> graph(n_nodes, vector<int>(n_nodes, 0));

    for (int i = 0; i < n_edges; ++i) {
        int src = 0, dst = 0, cap = 0;
        cin >> src >> dst >> cap;
        graph[src][dst] = cap;
    }

    cout << "Max Flow: " << maximum_flow(graph, src, dst) << endl;
}
