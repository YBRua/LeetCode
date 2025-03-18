// 207-course-schedule
using System.Collections.Generic;

public class Solution207 {
    public bool CanFinish(int numCourses, int[][] prerequisites) {
        List<int> in_degrees = new();
        Dictionary<int, List<int>> graph = new();

        for (int i = 0; i < numCourses; ++i) {
            in_degrees.Add(0);
            graph.Add(i, new List<int>());
        }

        foreach (int[] edge in prerequisites) {
            in_degrees[edge[0]]++;
            graph[edge[1]].Add(edge[0]);
        }

        // topology sort
        Queue<int> queue = new();
        for (int i = 0; i < numCourses; ++i) {
            if (in_degrees[i] == 0) {
                queue.Enqueue(i);
            }
        }

        while (queue.Count > 0) {
            int node = queue.Dequeue();
            numCourses--;

            foreach (int neighbor in graph[node]) {
                in_degrees[neighbor]--;
                if (in_degrees[neighbor] == 0) {
                    queue.Enqueue(neighbor);
                }
            }
        }

        return numCourses == 0;
    }
}
