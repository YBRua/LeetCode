#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Edge {
    public:
    int src;
    int dst;
    int weight;
    Edge(int s, int d, int w) {
        src = s;
        dst = d;
        weight = w;
    }
    Edge() {}
};

class Node {
    public:
    int node_id;
    int weight;
    Node(int nid, int w) {
        node_id = nid;
        weight = w;
    }
    Node() {}
    friend bool operator>(const Node &a, const Node &b) {
        return a.weight > b.weight;
    }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<Edge>> adj_list(n + 1);
    for (auto elist : times) {
        int src = elist[0];
        int dst = elist[1];
        int weight = elist[2];
        adj_list[src].push_back(Edge(src, dst, weight));
    }

    // dijkstra
    priority_queue<Node, vector<Node>, greater<Node>> heapq;
    vector<int> dists(n + 1, 1919810);
    dists[k] = 0;
    heapq.push(Node(k, 0));
    while (heapq.size()) {
        auto current = heapq.top();
        heapq.pop();
        for (auto edges : adj_list[current.node_id]) {
            int dst = edges.dst;
            if (dists[dst] > dists[current.node_id] + edges.weight) {
                dists[dst] = dists[current.node_id] + edges.weight;
                heapq.push(Node(dst, dists[dst]));
            }
        }
    }
    int max_time = 0;
    for (int i = 1; i <= n; ++i) {
        if (dists[i] == 1919810) {
            return -1;
        }
        if (dists[i] > max_time) {
            max_time = dists[i];
        }
    }
    return max_time;
}

/**
 * NOTE: The Dijkstra Algorithm (heap-optimized)
 * for node in nodes:
 *     dist[node] = INFTY
 *     prev[node] = None
 * dist[src] = 0
 * 
 * H = heapify(nodes)  # using dist-values as keys
 * while not H.empty():
 *     u = H.pop()
 *     for (u, v) in Edges[u]:
 *         if dist[v] > dist[u] + weight[(u, v)]:
 *             dist[v] = dist[u] + weight[(u, v)]
 *             prev[v] = u
 *             H.push(v)
 * 
 * return dist[tgt]
 */
