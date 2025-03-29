// 399-evaluate-division
using System.Collections.Generic;

public class Solution399 {
    private Dictionary<string, Dictionary<string, double>> graph = new Dictionary<string, Dictionary<string, double>>();
    private void buildGraph(IList<IList<string>> equations, double[] values) {
        for (int i = 0; i < equations.Count; ++i) {
            var eq = equations[i];
            var v = values[i];
            if (!graph.ContainsKey(eq[0])) {
                graph[eq[0]] = new Dictionary<string, double>();
                graph[eq[0]][eq[0]] = 1.0;
            }
            if (!graph.ContainsKey(eq[1])) {
                graph[eq[1]] = new Dictionary<string, double>();
                graph[eq[1]][eq[1]] = 1.0;
            }

            graph[eq[0]][eq[1]] = v;
            graph[eq[1]][eq[0]] = 1.0 / v;
        }
    }

    public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries) {
        buildGraph(equations, values);

        double[] res = new double[queries.Count];
        for (int i = 0; i < queries.Count; ++i) {
            var query = queries[i];

            // bfs ans search
            Queue<(string, double)> q = new();
            q.Enqueue((query[0], 1.0));

            HashSet<string> visited = new() { query[0] };

            bool found = false;
            while (q.Count > 0) {
                var (curr, val) = q.Dequeue();
                visited.Add(curr);

                if (!graph.ContainsKey(curr)) {
                    continue;
                }

                if (curr == query[1]) {
                    res[i] = val;
                    found = true;
                    break;
                }

                foreach (var item in graph[curr]) {
                    if (visited.Contains(item.Key)) {
                        continue;
                    }

                    q.Enqueue((item.Key, item.Value * val));
                }
            }

            if (!found) {
                res[i] = -1.0;
            }
        }

        return res;
    }
}