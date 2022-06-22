#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    class Node {
       public:
        int id;
        double nll;
        Node(int id, double log_prob) {
            this->id = id;
            this->nll = log_prob;
        }
        friend bool operator>(const Node &a, const Node &b) {
            return a.nll > b.nll;
        }
    };
    double maxProbability(int n, vector<vector<int>> &edges,
                          vector<double> &succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        vector<double> nlls(n, 1919810);
        priority_queue<Node, vector<Node>, greater<Node>> heapq;

        for (int i = 0; i < edges.size(); ++i) {
            int src = edges[i][0];
            int dst = edges[i][1];
            double prob = succProb[i];
            graph[src].push_back({dst, -log(prob)});
            graph[dst].push_back({src, -log(prob)});
        }

        heapq.push(Node(start, 0.0));
        while (heapq.size()) {
            Node node = heapq.top();
            heapq.pop();
            for (auto &tgt : graph[node.id]) {
                if (nlls[tgt.first] > node.nll + tgt.second) {
                    nlls[tgt.first] = node.nll + tgt.second;
                    heapq.push(Node(tgt.first, nlls[tgt.first]));
                }
            }
        }

        if (nlls[end] == 1919810) return 0.0;
        return exp(-nlls[end]);
    }
};
