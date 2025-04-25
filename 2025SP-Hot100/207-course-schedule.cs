using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution207 {
        // 207-course-schedule
        public bool CanFinish(int numCourses, int[][] prerequisites) {
            int[] inDegrees = new int[numCourses];
            Dictionary<int, List<int>> adjList = new();

            foreach (var prereq in prerequisites) {
                int src = prereq[0], dst = prereq[1];
                inDegrees[dst] += 1;
                if (!adjList.ContainsKey(src)) {
                    adjList[src] = new();
                }
                adjList[src].Add(dst);
            }

            Queue<int> bfsq = new();
            for (int i = 0; i < numCourses; ++i) {
                if (inDegrees[i] == 0) {
                    bfsq.Enqueue(i);
                }
            }

            while (bfsq.Count > 0) {
                int curr = bfsq.Dequeue();
                foreach (var nbr in adjList.GetValueOrDefault(curr, [])) {
                    inDegrees[nbr] -= 1;
                    if (inDegrees[nbr] == 0) {
                        bfsq.Enqueue(nbr);
                    }
                }
            }

            foreach (var indeg in inDegrees) {
                if (indeg > 0) {
                    return false;
                }
            }
            return true;
        }
    }
}
