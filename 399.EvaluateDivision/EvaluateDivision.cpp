#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<string> visited;
unordered_map<string, vector<pair<string, double>>> graph;

bool dfs_ans_search(string node, string tgt, double &ans) {
    if (node == tgt) {
        return true;
    }
    bool flag = false;
    visited.emplace(node);
    for (auto neighbours : graph[node]) {
        string next = neighbours.first;

        if (visited.count(next)) {
            continue;
        }

        double weight = neighbours.second;
        ans *= weight;
        flag = flag || dfs_ans_search(next, tgt, ans);
        if (flag) {
            return true;
        }
        ans /= weight;
    }
    visited.erase(node);
    return flag;
}

vector<double> calcEquation(vector<vector<string>>& equations,
                            vector<double>& values,
                            vector<vector<string>>& queries) {
    // build graph
    vector<double> anss;
    for (int i = 0; i < equations.size(); ++i) {
        string src = equations[i][0];
        string dst = equations[i][1];
        double weight = values[i];
        graph[src].push_back({dst, weight});
        graph[dst].push_back({src, 1 / weight});
    }
    for (auto q : queries) {
        double ans = 1.0;
        if (graph.count(q[0]) == 0 || graph.count(q[1]) == 0) {
            anss.push_back(-1.0);
            continue;
        }
        if (dfs_ans_search(q[0], q[1], ans)) {
            anss.push_back(ans);
        } else {
            anss.push_back(-1.0);
        }
        visited.clear();
    }

    return anss;
}