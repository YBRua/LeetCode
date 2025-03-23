from collections import defaultdict
from typing import List, Set


# 2685-count-the-number-of-complete-components
class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        adj_list = defaultdict(list)
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)

        connected_components = list()
        visited = set()

        def _dfs(current: int, running_set: Set[int]):
            if current in visited:
                return

            visited.add(current)
            running_set.add(current)

            for nbr in adj_list[current]:
                if nbr not in visited:
                    _dfs(nbr, running_set)

        for i in range(n):
            if i not in visited:
                running_set = set()
                _dfs(i, running_set)
                connected_components.append(running_set)

        n_ccc = 0
        for cc in connected_components:
            n_nodes = len(cc)
            n_edges = sum(len(adj_list[node]) for node in cc) // 2

            if n_edges == n_nodes * (n_nodes - 1) // 2:
                n_ccc += 1

        return n_ccc
