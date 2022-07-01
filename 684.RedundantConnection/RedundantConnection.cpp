#include <vector>

using namespace std;

class UnionFinder {
    public:
    vector<int> _parent;
    UnionFinder(int n_elements) {
        _parent.resize(n_elements, 0);
        for (int i = 0; i < _parent.size(); ++i) {
            _parent[i] = i;
        }
    }
    int find(int x) {
        if (_parent[x] != x) {
            _parent[x] = find(_parent[x]);
        }
        return _parent[x];
    }

    bool unite(int x, int y) {
        if (find(x) == find(y)) {
            return false;
        } else {
            int rx = find(x);
            int ry = find(y);
            _parent[rx] = _parent[ry];
            return true;
        }
    }
};


class Solution {
   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFinder ufs(edges.size() + 1);
        for (int i = 0; i < edges.size(); ++i) {
            vector<int> current_edge = edges[i];
            int src = current_edge[0], dst = current_edge[1];
            if (ufs.find(src) == ufs.find(dst)) {
                return current_edge;
            } else {
                ufs.unite(src, dst);
            }
        }
        return {};
    }
};
