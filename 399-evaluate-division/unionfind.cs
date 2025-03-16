// 399-evaluate-division
using System;
using System.Collections.Generic;
using System.Linq;

public class Solution399UnionFind {

    private class UnionFindSet {
        public Dictionary<string, string> parent;
        public Dictionary<string, double> weight;

        public UnionFindSet() {
            parent = new();
            weight = new();
        }

        public string Find(string key) {
            if (!parent.ContainsKey(key)) {
                parent[key] = key;
                weight[key] = 1.0;
            }

            if (parent[key] != key) {
                string idx = parent[key];
                parent[key] = Find(parent[key]);
                weight[key] *= weight[idx];
            }

            return parent[key];
        }

        public void Union(string key1, string key2, double w) {
            string parent1 = Find(key1);
            string parent2 = Find(key2);

            if (parent1 == parent2) {
                return;
            }

            weight[parent1] = weight[key2] * w / weight[key1];
            parent[parent1] = parent2;

            Find(key1);
        }

        public bool Reachable(string x, string y) {
            return parent.ContainsKey(x) && parent.ContainsKey(y) && Find(x) == Find(y);
        }

        public double GetWeight(string key) {
            return weight[key];
        }
    }

    public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries) {
        var ufs = new UnionFindSet();
        for (int i = 0; i < equations.Count; ++i) {
            ufs.Union(equations[i][0], equations[i][1], values[i]);
        }

        double[] res = Enumerable.Repeat(-1.0, queries.Count).ToArray();
        for (int i = 0; i < queries.Count; ++i) {
            var query = queries[i];

            if (!ufs.Reachable(query[0], query[1])) {
                continue;
            }

            res[i] = ufs.GetWeight(query[0]) / ufs.GetWeight(query[1]);
        }

        return res;
    }
}
