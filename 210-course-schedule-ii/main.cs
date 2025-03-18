using System;
using System.Collections.Generic;

public class Solution210 {
    public int[] FindOrder(int numCourses, int[][] prerequisites) {
        int[] inDegrees = new int[numCourses];
        Dictionary<int, List<int>> graph = new();

        for (int i = 0; i < numCourses; ++i) {
            graph.Add(i, new List<int>());
        }

        foreach (var edge in prerequisites) {
            inDegrees[edge[0]]++;
            graph[edge[1]].Add(edge[0]);
        }

        Queue<int> queue = new();
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0) {
                queue.Enqueue(i);
            }
        }

        List<int> result = new();
        while (queue.Count > 0) {
            var curr = queue.Dequeue();
            result.Add(curr);
            numCourses--;

            foreach (var nbr in graph[curr]) {
                inDegrees[nbr]--;
                if (inDegrees[nbr] == 0) {
                    queue.Enqueue(nbr);
                }
            }
        }

        return numCourses == 0 ? result.ToArray() : Array.Empty<int>();
    }
}